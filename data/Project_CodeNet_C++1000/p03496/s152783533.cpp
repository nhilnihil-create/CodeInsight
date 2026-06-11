#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1001001001001001;



int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<P> A(n);
    rep(i, n) {
      cin >> a[i];
      A[i].first=a[i];
      A[i].second=i;
    }
    sort(A.begin(),A.end());
    ll cnt=0;
    ll as=A.size();

    vector<P> ans;

    bool plus=false;
    ll a1=A[0].first;ll a2=A[as-1].first;

    if (a1>=0)plus=true;
    else if(a2>0){
      if (abs(a2)>abs(a1)){
        plus=true;
        rep(i,n){
          if (i==A[as-1].second)continue;
          a[i]+=a2;
          ans.push_back(make_pair(A[as-1].second+1,i+1));
        }
        cnt+=n-1;
      }
      else if(abs(a2)<=abs(a1)){
      //  plus=true;
        rep(i,n){
          if (i==A[0].second)continue;
          a[i]+=a1;
          ans.push_back(make_pair(A[0].second+1,i+1));
        }
        cnt+=n-1;
      }
    }
    cnt+=n-1;
    if (plus==true){
      rep(i,n-1){
        ans.push_back(make_pair(i+1,i+2));
      }
    }
    else if (plus==false){
      rep(i,n-1){
        ans.push_back(make_pair(n-i,n-i-1));
      }
    }

cout<<cnt<<endl;
rep(i,ans.size()){
  cout<<ans[i].first<<' '<<ans[i].second<<endl;
}



}
