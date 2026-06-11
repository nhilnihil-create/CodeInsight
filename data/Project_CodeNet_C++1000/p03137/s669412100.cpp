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
    ll n,m;
    cin>>n>>m;
    vector<ll> v(m);
    REP(i,m){
        cin>>v[i];
    }
    sort(ALL(v));
    vector<ll> d;
    REP(i,m-1){
        d.push_back(v[i+1]-v[i]);
    }
    sort(ALL(d));
    ll sum=0;
    REP(i,m-n){
        sum+=d[i];
    }
    cout<<sum;
    return 0;
}
