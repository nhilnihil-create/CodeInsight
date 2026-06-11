#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

inline int h(int n){
    return n*(n+1)/2;
}

signed main(){
    int a, b;
    cin >> a >> b;
    cout << h(b - a) - b << endl;
}