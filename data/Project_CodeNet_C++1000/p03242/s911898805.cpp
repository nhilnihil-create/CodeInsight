#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  rep(i,0,3){
    if(s[i]=='1') cout<<9;
    else cout<<1;
  }
  cout<<endl;
}