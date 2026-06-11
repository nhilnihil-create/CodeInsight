#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e10
typedef long long ll;
typedef long double ld;



int main(){
    ll d, n; cin>>d>>n;
    if(d==0&&n==100){
        cout<<101<<endl;
    }else if(d==1&&n==100){
        cout<<10100<<endl;
    }else if(d==2&&n==100){
        cout<<1010000<<endl;
    }else{
        cout<<pow(100,d)*n<<endl;
    }
    return 0;
}
