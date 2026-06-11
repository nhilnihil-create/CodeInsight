#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define intpow(a, n) (int)pow((long double) a, (long double) n)
#define int long long

signed main(){
    int a, b;
    cin >> a >> b;
    bool can = true;
    if(a > 8 || b > 8){
        can = false;
    }
    cout << (can ? "Yay!" : ":(") << endl;
}