#include<bits/stdc++.h>
#define int long long
#define all(v) (v).begin(),(v).end()
using namespace std;
const int INF=1000000000000;
int s(int a,int b){
  return a+b+min(a,b);
}
signed main(){
  int a,b,Q;
  cin>>a>>b>>Q;
  vector<int> A(a),B(b);
  for(int &i:A)cin>>i;
  for(int &i:B)cin>>i;
  while(Q--){
    int x;
    cin>>x;
    int it1=lower_bound(all(A),x)-A.begin(),it2=lower_bound(all(B),x)-B.begin();
    cout<<min({
      (it1!=a && it2!=b?max(abs(A[it1]-x),abs(B[it2]-x)):INF),
      (it1!=a && it2?s(abs(A[it1]-x),abs(B[it2-1]-x)):INF),
      (it1 && it2!=b?s(abs(A[it1-1]-x),abs(B[it2]-x)):INF),
      (it1 && it2?max(abs(A[it1-1]-x),abs(B[it2-1]-x)):INF)
    })<<endl;
  }
}