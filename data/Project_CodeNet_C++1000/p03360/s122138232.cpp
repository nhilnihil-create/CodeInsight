#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int a,b,c,k;cin>>a>>b>>c>>k;
    int sum = a+b+c;
    int cap = max(a, max(b,c));
    sum -= cap;
    rep(i,k)cap *= 2;
    
    cout << sum + cap << endl;
    
    return 0;
}