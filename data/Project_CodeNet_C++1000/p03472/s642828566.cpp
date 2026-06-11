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
    ll n,h;cin>>n>>h;
    vector<ll> a(n),b(n);
    REP(i,n)cin>>a[i]>>b[i];
    ll maxa=MAX(a), cnt=0;
    sort(ALL(b),greater<>());
    REP(i,n){
        if(maxa<=b[i]){
            h-=b[i];
            cnt++;
        }else{
            break;
        }
        if(h<=0){
            cout<<cnt<<endl;
            return 0;
        }
    }
    while(h>0){
        h-=maxa;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
