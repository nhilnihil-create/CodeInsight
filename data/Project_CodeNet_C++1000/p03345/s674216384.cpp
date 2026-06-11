#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k%2 == 1) cout <<-1*(a-b) << endl;
    else cout << a-b << endl;
}