#include <bits/stdc++.h>
using namespace std;
char in[55];
int main() {
  int a,b;scanf("%d%d",&a,&b);
  scanf("%s",in);
  in[b-1]+=32;
  printf("%s\n",in);
}
