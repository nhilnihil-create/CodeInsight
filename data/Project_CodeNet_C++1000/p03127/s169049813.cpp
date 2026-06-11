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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];
    ll answer;
    answer = gcd(a[0],a[1]);
    REP(i,n)answer = gcd(answer,a[i]);
    cout << answer << endl;
    return 0;
}