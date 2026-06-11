#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=100000000000000000;
ll MOD=1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n),v(n);
    int t=0; //合計時間
    rep(i,n) {cin >> a.at(i);a.at(i)*=2;t+=a.at(i);}
    rep(i,n) {cin >> v.at(i);v.at(i)*=2;}
    vector<int> mv(2*t+1); //0.5秒刻みで調べる各時刻の出しうる最高速度
    mv.at(0)=0;
    int nt=0;
    int q=0;
    
    for(int i=1;i<t;i++){
        nt++;
        if (nt==a.at(q) && v.at(q) >v.at(q+1)) {nt=0;q++;}
        mv.at(i)=min(mv.at(i-1)+1,v.at(q));
        if (nt==a.at(q) && v.at(q) <=v.at(q+1)) {nt=0;q++;}
    }
    mv.at(t)=0;
    for (double i=t-1;i>0;i--){ 
        mv.at(i)=min(mv.at(i+1)+1,mv.at(i));
    }
    int ans=0;
    int o=0;
    for (int i=1;i<t+1;i++){
        o++;
        ans+=(mv.at(2*i)+mv.at(2*i-1));
    }
    double yy=ans;
    yy=yy/4;
    printf("%.10f\n", yy);
}
