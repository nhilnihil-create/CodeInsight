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
    ll diffa = 0,diffb = 0;
    REP(i,n){
        cin >> a[i];
    }
    REP(i,n)cin >> b[i];
    REP(i,n){
        if(a[i] > b[i])diffb+=a[i]-b[i];
        else if(a[i] < b[i])diffa+=(b[i]-a[i])/2;
    }
    cerr << diffa << " " << diffb << endl;
    if(diffa < diffb)cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}