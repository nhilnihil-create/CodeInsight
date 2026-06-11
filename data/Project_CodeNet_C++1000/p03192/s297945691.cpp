#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string N; cin >> N;
    int ans=0;
    for (char c:N) ans+=(c=='2');
    cout << ans << '\n';
}