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
int a[100010];
signed main(){
  int n;cin>>n;
  int flag=0;
  int mi=INF;
  int sum=0;
  rep(i,n){
    cin>>a[i];
    if(a[i]<0)flag=1-flag;
    sum+=abs(a[i]);
    mi=min(mi,abs(a[i]));
  }
  cout<<sum-2*flag*mi<<endl;  
  return 0;
}
