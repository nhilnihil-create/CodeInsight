#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<P> ans;
int main(){
  string s,sk;
  cin>>sk;
  s='0'+sk;
  ll n=sk.length();
  if(s[1]=='0'||s[n]=='1'){
    cout<<-1<<endl;
    return 0;
  }
  for(int i=1;i<n;i++){
    if(s[i]!=s[n-i]){
      cout<<-1<<endl;
      return 0;
    }
  }

  ll k=1;
  for(int i=1;i<=n/2;i++){
    if(s[i]=='0'){
      ans.push_back(P(k,i+1));
    }
    else{
      ans.push_back(P(k,i+1));
      k=i+1;
    }
  }
  for(int i=n/2+2;i<=n;i++) ans.push_back(P(k,i));
  for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
