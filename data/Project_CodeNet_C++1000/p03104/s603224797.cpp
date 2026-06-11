#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int64_t f(int64_t x){
  x++;
  long long ans=0;
  for(int i=0;i<50;i++){
    long long l=(1LL<<(i+1));//整数xのibit目に1が現れる周期は2のi乗
    long long cnt=(x/l)*(l/2);//1周期に1が現れる個数は周期の半分.その数までの周期全体の1を数える。
    cnt+=max(0LL,(x%l)-(l/2));//0インデックスの周期のパターンはすべて{0,0,0...,0,1,1,1,...,1}となるから。
    if(cnt%2==1){
      ans+=(1LL<<i);
    }
  }
  return ans;
}
int main(){
  int64_t A,B;
  cin>>A>>B;
  int64_t ans=f(B)^f(A-1);
  cout<<ans<<endl;
  return 0;
}