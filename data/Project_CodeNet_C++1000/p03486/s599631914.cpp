#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(),t.end(),greater<char>());
    if(s < t)cout << "Yes" << endl;
    else cout << "No" << endl;
}