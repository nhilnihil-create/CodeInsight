#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k%2 == 0)  cout << a-b << endl;
    else cout << b-a << endl;
}
