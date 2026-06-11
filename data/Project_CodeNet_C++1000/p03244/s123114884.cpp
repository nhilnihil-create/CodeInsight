#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
 
int main() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  vector<int>L(100005),R(100005);
  for(int i=0;i<n;i++){
     if(i%2==0){
      L[v[i]]++;
     }
     if(i%2!=0){
      R[v[i]]++;
    }
  }
  int ml=*max_element(L.begin(),L.end());
  int ml2=0;
  int mli=0;
  for(int i=0;i<100005;i++){
    if(L[i]==ml){mli=i;}
    if(L[i]!=ml){ml2=max(L[i],ml2);}
  }
  for(int i=0;i<100005;i++){
    if(i!=mli){ml2=max(L[i],ml2);}
  }
  
  int mr=*max_element(R.begin(),R.end());
  int mr2=0;
  int mri=0;
  for(int i=0;i<100005;i++){
    if(R[i]==mr){mri=i;}
    if(R[i]!=mr){mr2=max(R[i],mr2);}
  }
  for(int i=0;i<100005;i++){
    if(i!=mri){mr2=max(R[i],mr2);}
  }
  if(mli!=mri){cout<<n-ml-mr<<endl;}
  if(mli==mri){cout<<min(n-ml-mr2,n-mr-ml2)<<endl;}
  return 0;
}