#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    if(b+1 >= c){
        cout << b+c << endl;
        return 0;
    }
    if(a+b+1>=c){
        cout << b+c << endl;
        return 0;
    }
    cout << b+a+1+b << endl;
    return 0;
}