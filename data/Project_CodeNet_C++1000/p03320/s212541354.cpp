#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  // deque<pair<LD,int>> ans;
  // ans.push_back({0,0});
  // int x,sum;
  // LD a;
  // for(int i=1;i<100000000;i++){
  //   x=i,sum=0;
  //   while(x){
  //     sum+=x%10;
  //     x/=10;
  //   }
  //   a=(LD)i/sum;
  //   while(ans.back().first>a){
  //     ans.pop_back();
  //   }
  //   ans.push_back({a,i});
  // }
  // while(!ans.empty()){
  //   cout << ans.front().second << endl;
  //   ans.pop_front();
  // }
  int k;
  cin >> k;
  deque<pair<LD,LL>> ans;
  ans.push_back({0,0});
  LL x,sum;
  LD a;
  for(int i=1;i<10000;i++){
    x=i,sum=0;
    while(x){
      sum+=x%10;
      x/=10;
    }
    a=(LD)i/sum;
    while(ans.back().first>a){
      ans.pop_back();
    }
    ans.push_back({a,i});
  }
  LL now=100;
  for(int i=0;i<12;i++){
    for(int j=100;j<1000;j++){
      x=j*now+now-1,sum=0;
      while(x>0){
        sum+=x%10;
        x/=10;
      }
      a=(LD)(j*now+now-1)/sum;
      // cout << j*now+now-1 SP sum SP a << endl;
      while(ans.back().first>a){
        ans.pop_back();
      }
      ans.push_back({a,j*now+now-1});
    }
    now*=10;
  }
  ans.pop_front();
  for(int i=0;i<k;i++){
    cout << ans.front().second << endl;
    ans.pop_front();
  }
  return 0;
}
