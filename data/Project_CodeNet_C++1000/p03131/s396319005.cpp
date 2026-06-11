#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int k,a,b;cin>>k>>a>>b;
  if(b-a<=2 || k+1<=a){
    cout<<k+1<<endl;
    return 0;
  }
  
  //int ans=0;
  k-=(a-1);
  cout<<a+(b-a)*(k/2)+(k%2)<<endl;
  
  return 0;
}
