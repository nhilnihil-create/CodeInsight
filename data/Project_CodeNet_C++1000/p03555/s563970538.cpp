#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    reverse(b.begin(),b.end());
    if(a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
}