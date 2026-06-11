#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(long long i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const double EPS = 1e-9;
const ll powll = 1LL<<1;

/*
while(!frag && cin >> a >>b, a|b)
*/

int main(void){
    int a[3],d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a,a+3);
    cout << a[0]+a[1]+a[2]*pow(2,d) << "\n";
}