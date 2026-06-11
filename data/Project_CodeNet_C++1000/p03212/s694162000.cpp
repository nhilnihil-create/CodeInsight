//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod=1e+9+7;

ll N;
string n;
vector<string>S;
void dfs(string s){
    if(s.size()<=n.size()){
        for(char c='3';c<='7';c+=2){
            S.push_back(s+c);
            dfs(s+c);
        }
    }
}
int main(){
  cin>>N;
  n=to_string(N);
  ll ans=0;
  dfs("");
  for (string v:S){
      ll num=0;
      bool c3=false,c5=false,c7=false;
      rep(i,v.size()){
          if(v[i]=='3')c3=true;
          if(v[i]=='5')c5=true;
          if(v[i]=='7')c7=true;
          num=num*10+v[i]-'0';
      }
      if(c3&&c5&&c7&&num<=N)ans++;
  }
  cout<<ans<<endl;
}



























































































