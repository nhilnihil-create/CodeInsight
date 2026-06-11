#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
using ll = long long;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
int a,b;cin >> a >>b;

if(a<=b)cout << a << endl;
else cout << a-1 << endl;

        return 0;
}
