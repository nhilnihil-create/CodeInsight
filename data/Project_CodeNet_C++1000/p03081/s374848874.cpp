#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<P> query[26];
int typ[200005]={0};
ll n;
bool L_ok(ll l){
  int qr_num=-1;
  while(1){
    int n_type=typ[l];
    if(query[n_type].size()==0) return true;
    int n_qr=upper_bound(query[n_type].begin(),query[n_type].end(),P(qr_num,99))-query[n_type].begin();
    if(n_qr==query[n_type].size()) return true;
    qr_num=query[n_type][n_qr].first;
    int dis=query[n_type][n_qr].second;
    if(dis==0) l--;
    else l++;
    if(l<=0) return false;
  }
}
bool R_ok(ll l){
  int qr_num=-1;
  while(1){
    int n_type=typ[l];
    if(query[n_type].size()==0) return true;
    int n_qr=upper_bound(query[n_type].begin(),query[n_type].end(),P(qr_num,99))-query[n_type].begin();
    if(n_qr==query[n_type].size()) return true;
    qr_num=query[n_type][n_qr].first;
    int dis=query[n_type][n_qr].second;
    if(dis==0) l--;
    else l++;
    if(l>n) return false;
  }
}
int main(){
  ll q;
  cin>>n>>q;
  string s;
  cin>>s;
  for(int i=0;i<n;i++){
    typ[i+1]=(int)(s[i]-'A');
  }
  for(int i=0;i<q;i++){
    char a,d;
    cin>>a>>d;
    if(d=='L') query[(int)(a-'A')].push_back(P(i,0));
    else query[(int)(a-'A')].push_back(P(i,1));
  }
  ll llb=0,lrb=n+1;
  while(lrb-llb>1){
    ll mid=(llb+lrb)/2;
    if(L_ok(mid)) lrb=mid;
    else llb=mid;
  }
  ll rlb=0,rrb=n+1;
  while(rrb-rlb>1){
    ll mid=(rlb+rrb)/2;
    if(R_ok(mid)) rlb=mid;
    else rrb=mid;
  }
  cout<<max((ll)0,rlb-llb)<<endl;
}
