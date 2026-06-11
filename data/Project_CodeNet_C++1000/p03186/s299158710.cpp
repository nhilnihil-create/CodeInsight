#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    if(c>a+b)cout << a+b+b+1 << endl;
    else cout << c+b << endl;

}
