//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> >vvi;
const ll MOD=1000000007LL;
int main(){
  ll N;
  cin>>N;
  for(ll h=1;h<=3500;h++){
    for(ll n=1;n<=3500;n++){
      if(4*h*n-N*(n+h)==0)continue;
      if((N*h*n)%(4*h*n-N*(n+h))==0){
        if(N*h*n/(4*h*n-N*(n+h))<=0)continue;
        cout<<h<<" "<<n<<" "<<N*h*n/(4*h*n-N*(n+h))<<endl;
        return 0;
      }
    }
  }
}
      