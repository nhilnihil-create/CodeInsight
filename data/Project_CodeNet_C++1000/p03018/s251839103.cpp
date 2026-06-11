#include <bits/stdc++.h>
using namespace std;
int i,j,k,a,n;
char s[200200];
long long r;
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) if (s[i]=='A') {
    for (j=i; j<n && s[j]=='A'; j++);
    a+=j-i;
    for (k=j; k+1<n && s[k]=='B' && s[k+1]=='C'; k+=2);
    if (k>j) {
      r+=a*((k-j)/2LL);
      i=k-1;
    } else {
      a=0; i=j;
    }
  } else a=0;
  printf("%lld\n",r);
  return 0;
}
