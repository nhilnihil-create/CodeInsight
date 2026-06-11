#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
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
    vector<vector<ll>> c(3,vector<ll>(3));
    REP(i,3)REP(j,3)cin>>c[i][j];
    bool is=true;
    REP(i,2){
        REP(j,2){
            ll d1=c[i][j]-c[i][j+1], d2=c[i+1][j]-c[i+1][j+1];
            ll d3=c[i][j]-c[i+1][j], d4=c[i][j+1]-c[i+1][j+1];
            if(d1!=d2 || d3!=d4){
                is=false;
                break;
            }
        }
    }
    string ans;
    if(is){
        ans="Yes";
    }else{
        ans="No";
    }
    cout<<ans<<endl;
    return 0;
}
