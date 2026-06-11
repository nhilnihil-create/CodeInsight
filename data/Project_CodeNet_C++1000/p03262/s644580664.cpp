#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,x,g;
    cin >> n >> x;
    cin >> g;
    g = abs(g-x);
    rep(i,n-1){
        int a;
        cin >> a;
        g = gcd(g,abs(a-x));
    }
    cout << g << endl;
}
