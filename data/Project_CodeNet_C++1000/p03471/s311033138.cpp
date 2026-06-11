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
    ll n,y;cin>>n>>y;
    REP(i,n+1){
        REP(j,n-i+1){
            ll money=10000*(n-i-j)+5000*i+1000*j;
            if(money==y){
                cout<<n-i-j<<" "<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;

    /*
    if(n<=a){
        if(a*10000==y){
            cout<<a<<" 0 0"<<endl;
            return 0;
        }else{
            cout<<"-1 -1 -1"<<endl;
            return 0;
        }
    }else if(n<=b){
        REP(i,a+1){
            REP(j,b+1){
                if(i*10000+j*5000==y && i+j==n){
                    cout<<i<<" "<<j<<" 0"<<endl;
                    return 0;
                }
            }
        }
        cout<<"-1 -1 -1"<<endl;
        return 0;
    }else{
        REP(i,a+1){
        if(i*10000>y)break;
        REP(j,b+1){
            if(i*10000+j*5000>y)break;
            REP(k,c+1){
                if(i*10000+j*5000+k*1000>y)break;
                ll money=i*10000+j*5000+k*1000;
                ll bill=i+j+k;
                if(money==y && bill==n){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
    }
    */
}
