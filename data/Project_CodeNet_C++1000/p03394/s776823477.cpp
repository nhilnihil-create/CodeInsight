//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=1000000007LL;
const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll n;cin>>n;
  deque<ll>three,two,four,six,ans;
  ans.push_back(3);
  ans.push_back(9);
  ans.push_back(2);
  ans.push_back(4);
  for(ll i=1;i<=30000;i++){
    if(i==3||i==9||i==2||i==4)continue;
    if(i%6==3)three.push_back(i);
    if(i%6==2)two.push_back(i);
    if(i%6==4)four.push_back(i);
    if(i%6==0)six.push_back(i);
  }
  if(n==3){
    cout<<2<<" "<<5<<" "<<63<<endl;
    return 0;
  }
  n-=4;
  while(n>0){
    if(three.size()>0&&n!=1){
      ans.push_back(three.front());
      three.pop_front();
      ans.push_back(three.front());
      three.pop_front();
      n-=2;
    }
    else if(two.size()>0&&n!=1){
      ans.push_back(two.front());
      two.pop_front();
      ans.push_back(four.front());
      four.pop_front();
      n-=2;
    }
    else {
      ans.push_back(six.front());
      six.pop_front();
      n--;
    }
         
  }
  rep(i,ans.size()){
    cout<<ans[i];
    if(i==ans.size()-1)cout<<endl;
    else cout<<" ";
  }
}
  
