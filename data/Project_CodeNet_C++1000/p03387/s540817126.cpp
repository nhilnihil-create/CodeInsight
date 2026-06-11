#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int d=max(a,max(b,c));
  int ans=(d-a)/2+(d-b)/2+(d-c)/2;
  int p=(d-a)%2+(d-b)%2+(d-c)%2;
  if(p==1)ans+=2;
  if(p==2)ans+=1;
  if(p==0)ans+=0;
  cout << ans;
}