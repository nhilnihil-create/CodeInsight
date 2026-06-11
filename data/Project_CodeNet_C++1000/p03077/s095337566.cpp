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

ll natural(ll a, ll b){
    if(a-b>0){
        return a-b;
    }else{
        return 0;
    }
}

int main(){
    ld n,a,b,c,d,e;
    cin>>n>>a>>b>>c>>d>>e;
    vector<ld> nums={a,b,c,d,e};
    ld min=MIN(nums);
    ll time=ceil(n/min)+4;
    cout<<time;
    return 0;
}
