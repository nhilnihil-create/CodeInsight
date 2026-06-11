#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
long long gcd(long long a, long long b)//最大公約数
{
   if (b == 0)
   {
       return a;
   }
    return gcd(b, a%b);
}

long long lcm(long long a, long long b) //最小公倍数
{
    return (a/gcd(a, b))*b;
}
int main() {
    int N ;
    ll X;
    cin >> N >> X;
    vector<ll>XP(N+1);
    vector<ll>XV(N);
    ll lcmN = 100000000001;
    XP[0]=X;
    rep(i, 1, N+1){
        cin >> XP[i];
    }
    sort(XP.begin(), XP.end());
    rep(i, 0, N){
        XV[i] = XP[i+1] - XP[i];
    }
    rep(i, 0, XV.size()-1){
        ll tmp = gcd(XV[i],XV[i+1]);
        lcmN = min(tmp, lcmN);
    }
    if(N-1 == 0){
        cout << XV[0] << endl;
        return 0;
    }
    cout << lcmN << endl;
    return 0;
}
