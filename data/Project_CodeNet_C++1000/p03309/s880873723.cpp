#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <sstream>
#include <bitset>
#include <stack>
#include <cstdlib>
#include <utility> //pair

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef long long ll;

using namespace std;

int main() {

    ll n;
    cin >> n;

    vector<ll> a(n);

    FOR(i, 0, n){
        cin >> a[i];
        a[i] = a[i] -(i+1);
    }

    sort(a.begin(),a.end());

    ll b,b1,b2;
    ll ans=0;
    ll ans1=0,ans2=0;
    if(n%2!=0){
        b = a[n/2]; //中央値
        FOR(i, 0, n){
            ans += abs(a[i]-b);
        }
    }else{
        b1 = a[n/2];
        b2 = a[n/2-1];
        FOR(i, 0, n){
            ans1 += abs(a[i]-b1);
            ans2 += abs(a[i]-b2);
        }
        ans = min(ans1,ans2);
    }

    cout <<  ans <<  endl;

    return 0;
}