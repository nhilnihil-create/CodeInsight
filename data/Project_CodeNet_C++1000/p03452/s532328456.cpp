#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000)
#define MAX_M (200000)
#define MAX_COR (1000000000)

int K;
int bases[MAX_N], offsets[MAX_N];

void uf_init(int N) {
  K = N;
  for (int i = 0; i < K; i++) {
    bases[i] = i;
    offsets[i] = 0;
  }
}

int uf_find_root_r(int k, int *p_offset) {
  // the root's base is itself
  if (bases[k] == k) {
    *p_offset = 0;
    return k;
  }
  // recursively search for the root (and optimize)
  int ret = uf_find_root_r(bases[k], p_offset);
  *p_offset += offsets[k];
  bases[k] = ret;
  offsets[k] = *p_offset;
  return ret;
}

int uf_find_base(int k) {
  int offset;
  return uf_find_root_r(k, &offset);
}

int uf_add(int l, int r, int d) {
  const int base_l = uf_find_base(l), offset_l = offsets[l];
  const int base_r = uf_find_base(r), offset_r = offsets[r];
  // printf("insert rule: l = %d, r = %d, d = %d\n", l, r, d);
  // printf("before: base_l = %d, offset_l = %d, base_r = %d, offset_r = %d\n",
  //        base_l, offset_l, base_r, offset_r);
  if (base_l == base_r) {  // same root, check for inconsistencies
    return offset_r - offset_l == d;
  } else {  // they are not related yet
    bases[base_r] = base_l;
    offsets[base_r] = d - offset_r + offset_l;
    return 1;
  }
}

int all_offsets_below(int thresh) {
  for (int i = 0; i < K; i++) {
    uf_find_base(i);
    if (offsets[i] > thresh) {
      return 0;
    }
  }
  return 1;
}

void uf_print() {
  printf("bases:\n");
  for (int i = 0; i < K; i++) {
    printf("%5d ", bases[i]);
  }
  printf("\noffsets:\n");
  for (int i = 0; i < K; i++) {
    printf("%5d ", offsets[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  // read inputs
  int N, M, Ls[MAX_M], Rs[MAX_M], Ds[MAX_M];
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &Ls[i], &Rs[i], &Ds[i]);
    Ls[i]--;  // NOTE : modified input
    Rs[i]--;  // NOTE : modified input
  }

  // initialize the uf tree
  uf_init(N);
  // keep inserting rules
  int possible = 1;
  for (int i = 0; i < M; i++) {
    if (!uf_add(Ls[i], Rs[i], Ds[i])) {
      possible = 0;
      break;
    }
    // uf_print();
  }
  if (possible && all_offsets_below(MAX_COR)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
