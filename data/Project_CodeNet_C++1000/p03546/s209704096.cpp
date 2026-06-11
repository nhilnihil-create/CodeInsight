#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll INF=pow(10, 18);
    int h,w;cin>>h>>w;
    vector<vector<ll>> c(10,vector<ll> (10));
    REP(i,10)REP(j,10)cin>>c[i][j];
    REP(k,10)REP(i,10)REP(j,10)
        if(c[i][j]>c[i][k]+c[k][j])c[i][j]=c[i][k]+c[k][j];
    ll sum=0;
    REP(i,h)REP(j,w){
        ll a;cin>>a;
        if(a>=0){
            sum+=c[a][1];
        }
    }
    cout<<sum<<endl;
    return 0;
}
