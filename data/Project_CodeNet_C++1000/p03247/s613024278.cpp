#include <cstdio>
int n, x, y, a[1005], b[1005], o;
char c[] = "RUDL";
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &x, &y);
    if(i && x+y&1^o) return puts("-1")*0;
    else o = x+y&1;
    if(!o) x++;
    a[i] = (1<<30)-(x+y+1)/2; b[i] = (1<<30)-(x-y+1)/2;
  }
  printf("%s", o ? "31\n" : "32\n 1 ");
  for(int i = 0; i < 31; i++) printf("%d%s", 1<<i, i == 30 ? "\n" : " ");
  for(int i = 0; i < n; i++){
    if(!o) printf("L");
    for(int j = 0; j < 31; j++) printf("%c", c[((a[i]>>j)&1)*2+((b[i]>>j)&1)]);
    puts("");
  }
}