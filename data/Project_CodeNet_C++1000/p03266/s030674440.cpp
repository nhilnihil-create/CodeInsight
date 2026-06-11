#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const ll max_co = 3234600000;
int mod =1000000007;
int main(){
   ll n,k;
   cin>>n>>k;
   ll c=n/k;
   ll d=c*c*c;
   if(k%2==0){
      if(k*c+k/2<=n)c++;
      d+=c*c*c;
   }
   cout<<d<<endl;
}
