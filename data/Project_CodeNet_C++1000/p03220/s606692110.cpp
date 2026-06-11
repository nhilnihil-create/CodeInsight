#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  int N,T,A;
  cin>>N>>T>>A;
  int H[N];
  rep(i,N) cin >> H[i];
  int ans;
  int cnt=INF;
  rep(i,N){
    int h=abs(1000*A-(1000*T-H[i]*6));
    if(h<cnt){
      cnt=h;
      ans=i+1;
    }
  }
  cout<<ans<<endl;
}