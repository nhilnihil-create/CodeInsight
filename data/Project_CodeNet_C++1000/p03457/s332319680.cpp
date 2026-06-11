#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
    ll n;cin>>n;
    vector<vector<ll>> v(n, vector<ll> (3));
    REP(i,n)REP(j,3)cin>>v[i][j];
    string ans="Yes";
    ll dt,dx,dy;
    dt=v[0][0], dx=v[0][1], dy=v[0][2];
    while(dt>=0){
        if(dx+dy==dt){
            break;
        }else{
            dt-=2;
            continue;
        }
    }
    if(dt<0)ans="No";
    REP(i,n-1){
        dt=v[i+1][0]-v[i][0];
        dx=abs(v[i+1][1]-v[i][1]);
        dy=abs(v[i+1][2]-v[i][2]);
        while(dt>=0){
            if(dx+dy==dt){
                break;
            }else{
                dt-=2;
                continue;
            }
        }
        if(dt<0)ans="No";
    }
    cout<<ans<<endl;
    return 0;
}
