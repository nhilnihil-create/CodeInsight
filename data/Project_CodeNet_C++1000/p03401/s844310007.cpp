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
    ll n;
    cin>>n;
    vector<ll> v={0};
    REP(i,n){
        ll a;cin>>a;
        v.push_back(a);
    }
    v.push_back(0);
    ll sum=0;
    REP(i,n+2){
        sum+=abs(v[i]-v[i+1]);
    }
    FOR(i,1,n+1){
        ll ans;
        ans=sum+abs(v[i-1]-v[i+1])-abs(v[i-1]-v[i])-abs(v[i]-v[i+1]);
        cout<<ans<<endl;
    }
    
    return 0;
}
