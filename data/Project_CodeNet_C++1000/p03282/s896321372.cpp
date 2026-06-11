#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  ll k;
  cin>>s>>k;
  int i=0;
  while(i<s.size() && s[i]=='1'){
    i++;
  }
  if(k<=i){
    cout<<'1'<<endl;
  }
  else{
    cout<<s[i]<<endl;
  }
}