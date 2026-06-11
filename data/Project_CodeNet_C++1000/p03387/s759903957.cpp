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
    ll a,b,c,count=0;
    cin>>a>>b>>c;
    vector<ll> v={a,b,c};
    sort(ALL(v));
    a=v[0],b=v[1],c=v[2];
    while(b<c){
        a++;
        b++;
        count++;
    }
    if((c-a)%2==0){
        while(a<c){
            a+=2;
            count++;
        }
    }else{
        b++;
        c++;
        count++;
        while(a<c){
            a+=2;
            count++;
        }
    }
    cout<<count;
    return 0;
}
