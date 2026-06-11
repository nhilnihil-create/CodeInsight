#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  string s;
  cin>>s;
  int cnt0=0;
  int cnt1=0;
  rep(i,len(s)){
    if(s[i]=='0') cnt0++;
    if(s[i]=='1') cnt1++;
  }
  cout<<len(s)-abs(cnt0-cnt1)<<endl;
}