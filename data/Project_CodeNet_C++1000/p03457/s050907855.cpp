#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define lp(i,n) for(int i=0;i<(n);i++)
#define lps(i,j,n) for(int i=j;i<n;i++)

#define fordebug int hoge;cin>>hoge;

#define DEKAI 1000000007
#define floot10 cout<<fixed<<setprecision(15)
#define all(v) v.begin(),v.end()
double PI = acos(-1);

signed main(){
  int n;
  cin>>n;
  int placex=0,placey=0;
  int time=0;//初期地点と、時間
  string ans="Yes";
  
  lp(i,n){
    int t,x,y;
    cin>>t>>x>>y;
    
    //まず、時間内に到達できる？
    int need_time=abs(placex-x)+abs(placey-y);//最短の所要時間
    if(time+need_time>t){
      ans="No";
      //到達できないならNO
    }

    int remain_time=(t-time-need_time);//余った時間。
    //余った時間が2の倍数でないなら、時間潰し失敗
    if(remain_time%2!=0){
      ans="No";
    }

    time=t;
    placex=x;
    placey=y;
    //次の計算のために、初期地点と時間を更新
  }
  cout<<ans<<endl;
  return 0;
}
