#include <iostream>

using namespace std;

int L[100000],R[100000],L1[100000],R1[100000],X[100000],Y[100000],F[100000];

int part(int p, int r) {
  int i=p-1,j,temp;
  for (j=p;j<r;j++) {
    if (L1[j] <= L1[r]) {
      i++;
      temp=L1[i];
      L1[i]=L1[j];
      L1[j]=temp;
      temp=X[i];
      X[i]=X[j];
      X[j]=temp;
    }
  }
  temp=L1[i+1];
  L1[i+1]=L1[r];
  L1[r]=temp;
  temp=X[i+1];
  X[i+1]=X[r];
  X[r]=temp;
  return i+1;
}

void qsort(int p,int r){
  if (p < r) {
    int q=part(p,r);
    qsort(p,q-1);
    qsort(q+1,r);
  }
}

int part2(int p, int r) {
  int i=p-1,j,temp;
  for (j=p;j<r;j++) {
    if (R1[j] <= R1[r]) {
      i++;
      temp=R1[i];
      R1[i]=R1[j];
      R1[j]=temp;
      temp=Y[i];
      Y[i]=Y[j];
      Y[j]=temp;
    }
  }
  temp=R1[i+1];
  R1[i+1]=R1[r];
  R1[r]=temp;
  temp=Y[i+1];
  Y[i+1]=Y[r];
  Y[r]=temp;
  return i+1;
}

void qsort2(int p,int r){
  if (p < r) {
    int q=part2(p,r);
    qsort2(p,q-1);
    qsort2(q+1,r);
  }
}

int main(){
  int i,N,l,r,x;
  long long K,K2;
  cin >> N;
  for (i=0;i<N;++i) {
    cin >> L[i] >> R[i];
    L1[i]=L[i];
    R1[i]=R[i];
    X[i]=i;
    Y[i]=i;
    F[i]=0;
  }
  qsort(0,N-1);
  qsort2(0,N-1);
  l=N-1;
  r=0;
  K=0;
  x=0;
  for (i=0;i<N;++i) {
    while (F[Y[r]]==1) {
      r++;
    }
    if (R1[r] < x) {
      K+=abs(x-R1[r]);
      x=R1[r];
    } else {
      break;
    }
    F[Y[r]]=1;
    r++;
    ++i;
    if (i==N) {
      break;
    }
    while (F[X[l]]==1) {
      l--;
    }
    if (L1[l] > x) {
      K+=abs(x-L1[l]);
      x=L1[l];
    } else {
      break;
    }
    F[X[l]]=1;
    l--;
  }
  K+=abs(x);

  l=N-1;
  r=0;
  K2=0;
  x=0;
  for (i=0;i<N;++i) {
    while (F[X[l]]==2) {
      l--;
    }
    if (L1[l] > x) {
      K2+=abs(x-L1[l]);
      x=L1[l];
    } else {
      break;
    }
    F[X[l]]=2;
    l--;
    ++i;
    if (i==N) {
      break;
    }
    while (F[Y[r]]==2) {
      r++;
    }
    if (R1[r] < x) {
      K2+=abs(x-R1[r]);
      x=R1[r];
    } else {
      break;
    }
    F[Y[r]]=2;
    r++;
  }
  K2+=abs(x);
  if (K>K2) {
    cout << K << endl;
  } else {
    cout << K2 << endl;
  }
  return 0;
}
