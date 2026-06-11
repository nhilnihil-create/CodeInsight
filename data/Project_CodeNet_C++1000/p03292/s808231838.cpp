#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int ans=300;
  int part_1=abs(a-max(b,c))+abs(max(b,c)-min(b,c));
  int part_2=abs(b-max(c,a))+abs(max(c,a)-min(c,a));  
  int part_3=abs(c-max(a,b))+abs(max(a,b)-min(a,b)); 
  ans=min(part_1,min(part_2,part_3));
  cout << ans;
}
