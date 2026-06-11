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
    ll n;cin>>n;
    vector<ll> v(n);
    REP(i,n)cin>>v[i];
    sort(ALL(v),greater<>());
    ll alice=0,bob=0;
    REP(i,n){
        if(i%2==0){
            alice+=v[i];
        }else{
            bob+=v[i];
        }
    }
    cout<<alice-bob<<endl;
    return 0;
}
