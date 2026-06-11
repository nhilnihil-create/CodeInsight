#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>hn;
  int Max=3500;
  for(int h=1;h<=Max;h++){
    for(int w=1;w<=Max;w++){
      if(N*w+N*h-4*h*w==0)continue;
      if((-N*h*w)%(N*w+N*h-4*h*w))continue;
      int n=(-N*h*w)/(N*w+N*h-4*h*w);
      if(n>=0){
        cout<<n<<" "<<h<<" "<<w<<endl;
        return 0;
      }
    }
  }
  return 0; 
}
