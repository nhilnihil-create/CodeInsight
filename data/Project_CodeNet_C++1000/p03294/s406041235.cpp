#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const ll MOD = 1000000007LL;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    rep(i, n){
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum-n << endl;
}