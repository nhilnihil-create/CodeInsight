#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll d,n; cin >> d >> n;
    if(n==100) n++;
    rep(i,d) n*=100;
    cout << n << endl;
}