#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
#define P pair<int, int>
#define ll long long
const int MOD = 1000000007;
//bitset<64>(x).count()
//fixed << setprecision(15) << 

  char in[120];
  pair<pair<string,int>,int> p[110];
  int main(){
    int a;scanf("%d",&a);
    for(int i=0;i<a;i++){
      int t;scanf("%s%d",in,&t);
      string tmp=in;
      p[i]=make_pair(make_pair(in,-t),i);
    }
    std::sort(p,p+a);
    for(int i=0;i<a;i++)printf("%d\n",p[i].second+1);
  }

