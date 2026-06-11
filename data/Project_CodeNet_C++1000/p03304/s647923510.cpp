#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using namespace std;
typedef long long ll;
using ld = long double;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  ll n,m,d;
  cin >> n >> m >> d;
  if(n<=2*d){
    cout << (ld)2*(n-d)*(m-1)/(n*n) << "\n";
    return 0;}
  if(d==0){cout << (ld)(m-1)/n << "\n";return 0;}
  cout(10)<<(ld)2*(n-d)*(m-1)/(n*n)<<endl;
  
  return 0;
}