#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n),b(n);
    REP(i,n)cin >> a[i]; REP(i,n)cin >> b[i];
    vector<ll>dif(n);
    REP(i,n)dif[i] = a[i]-b[i];
    SORT(dif);
    int m = 0;
    ll total = 0;
    REP(i,n){
        if(dif[i] < 0){
            m++;
            total-=dif[i];
        }else break;
    }
    reverse(ALL(dif));
    ll temp=0;
    int p = 0;
    if(temp >= total){
        cerr << "aaa" << endl;
        cout << 0 << endl;
        return 0;
    }
    REP(i,n){
        temp+=dif[i];
        p++;
        if(temp >= total){
            cout << m+p << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}