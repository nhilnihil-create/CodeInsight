#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;

int main(){
  int A,B,Q;
  cin>>A>>B>>Q;
  vector<ll> s(A),t(B),x(Q);
  for(int i(0);i<A;i++){
    cin>>s[i];
  }
  for(int i(0);i<B;i++){
    cin>>t[i];
  }
  for(int i(0);i<Q;i++){
    cin>>x[i];
  }
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());

  for(int i(0);i<Q;i++){
    ll mt,ht,mz,hz;
    auto mti = lower_bound(t.begin(),t.end(),x[i]);
    if(mti == t.end()){
      mt = (ll)1e18;
      ht = *(mti-1);
    }else{
      mt = *mti;
      if(mti == t.begin()) ht = -1e18;
      else ht = *(mti-1);
    }
    
    auto mzi = lower_bound(s.begin(),s.end(),x[i]);
    if(mzi == s.end()){
      mz = (ll)1e18;
      hz = *(mzi-1);
    }else{
      mz = *mzi;
      if(mzi == s.begin()) hz = -1e18;
      else hz = *(mzi-1);
    }


    //cout << mt << " " << mz <<" "<<ht<<" " << hz<< endl;
    ll tmp1(max(mt,mz)-x[i]),tmp2(x[i]-min(ht,hz)),tmp3(mt-x[i]+x[i]-hz+min(mt-x[i],x[i]-hz)),tmp4(mz-x[i]+x[i]-ht+min(mz-x[i],x[i]-ht));
    //cout << tmp1 <<" "<< tmp2 <<" "<< tmp3 <<" "<< tmp4 << endl;
    cout << min({tmp1,tmp2,tmp3,tmp4}) << endl;
  }
  return 0;
}
