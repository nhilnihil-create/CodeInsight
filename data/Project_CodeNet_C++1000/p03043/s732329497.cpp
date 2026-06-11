#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
    ll n,k;
    cin>>n>>k;
    ll point;
    double p=0;
    FOR(i,1,n+1){
        point=i;
        ll count=0;
        while(point<k){
            point*=2;
            count++;
        }
        p+=1/(pow(2,count)*n);
    }
    cout << fixed << setprecision(10)<<p;
    return 0;
}