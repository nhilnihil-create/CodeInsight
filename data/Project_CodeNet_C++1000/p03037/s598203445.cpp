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
    ll a=0,b=pow(10,5),l,r;
    REP(i,m){
        cin>>l>>r;
        if(a<l){
            a=l;
        }
        if(r<b){
            b=r;
        }
    }
    if(b-a+1>=0){
        cout<<b-a+1;
    }else{
        cout<<0;
    }
    return 0;
}
