#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve() {
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    if(s<t) cout<<"Yes\n";
    else cout<<"No\n";
}

int main() {
    solve();
    return 0;
}