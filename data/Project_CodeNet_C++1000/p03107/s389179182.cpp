#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  int x=0;
  int y=0;
  
  rep(i,s.size()){
    if(s[i] == '0')
      x++;
    else
      y++;
  }
  int res = min(x,y)*2;
  cout<<res<<endl;
}