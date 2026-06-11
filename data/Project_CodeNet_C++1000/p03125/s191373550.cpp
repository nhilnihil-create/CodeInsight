#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b; cin >> a >> b;

    cout << (b%a?b-a:a+b);
}
