#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int> v;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a=0,b,c,d=0,e=0,f=0,g=0,i;
  string s;
  for(int n=0;n<4;n++){
    cin >>s[n];
    if(s[n]=='1') d++;
    if(s[n]=='9') e++;
    if(s[n]=='7') f++;
    if(s[n]=='4') g++;
  }
  if(d>0&&e>0&&f>0&&g>0) cout <<"YES\n";
  else cout <<"NO\n";
  return (0);
}
