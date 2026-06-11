#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll n;cin>>n;
    vector<ll> v(n),w(n);
    REP(i,n){
        cin>>v[i];
    }
    REP(i,n){
        cin>>w[i];
    }
    ll max=0;
    REP(i,n){
        ll candy=0;
        REP(j,i+1){
            candy+=v[j];
        }
        for(int k=n-1; k>=i ;k--){
            candy+=w[k];
        }
        if(max<candy){
            max=candy;
        }
    }
    
    cout<<max;
    return 0;
}
