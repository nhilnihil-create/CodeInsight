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
    ll n, y;cin>>n>>y;
    ll a,b,c;
    REP(i,n+1)REP(j,n+1){
        int k=n-i-j;
        if(10000*i+5000*j+1000*k==y && k>=0){
            cout<<i<<" "<<j<<" "<<k<<endl;
            return 0;
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}
