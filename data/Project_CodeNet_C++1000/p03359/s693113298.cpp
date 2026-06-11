#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int a,b; cin>>a>>b;
  if(b>=12) b=12;
  if(a>b) b=a-1;
  printf("%d\n",min(a,b));  
  return 0;
}
