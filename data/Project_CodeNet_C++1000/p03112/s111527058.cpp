#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  ll a,b,q;
  cin>>a>>b>>q;
  
  vector<ll> A(a),B(b),X(q);
  rep(i,a) cin>>A[i];
  rep(i,b) cin>>B[i];
  rep(i,q) cin>>X[i];
  
  vector<ll> An(a),Bn(b);
  rep(i,a){
    auto itr=upper_bound(ALL(B),A[i]);
    if(itr==B.begin()) An[i]=B[0]-A[i];
    else if(itr==B.end()) An[i]=A[i]-B[b-1];
    else An[i]=min(*itr-A[i],A[i]-*(itr-1));
  }
  rep(i,b){
    auto itr=upper_bound(ALL(A),B[i]);
    if(itr==A.begin()) Bn[i]=A[0]-B[i];
    else if(itr==A.end()) Bn[i]=B[i]-A[a-1];
    else Bn[i]=min(*itr-B[i],B[i]-*(itr-1));
  }
  
  ll am,bm,n1,n2;
  rep(i,q){
    auto itr1=upper_bound(ALL(A),X[i]);
    if(itr1==A.begin()) am=A[0]+An[0]-X[i];
    else if(itr1==A.end()) am=X[i]-A[a-1]+An[a-1];
    else{
      n1=itr1-A.begin();
      am=min(A[n1]-X[i]+An[n1],X[i]-A[n1-1]+An[n1-1]);
    }
    
    auto itr2=upper_bound(ALL(B),X[i]);
    if(itr2==B.begin()) bm=B[0]+Bn[0]-X[i];
    else if(itr2==B.end()) bm=X[i]-B[b-1]+Bn[b-1];
    else{
      n2=itr2-B.begin();
      bm=min(B[n2]-X[i]+Bn[n2],X[i]-B[n2-1]+Bn[n2-1]);
    }
    
    cout<<min(am,bm)<<endl;
  }

  return 0;
}