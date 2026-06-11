#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    string s,t;
    cin >> s >> t;
    vector<int> a(26,0),b(26,0);
    int n = s.size();
    rep(i,n) {
        a[s[i]-'a']++;
    }
    rep(i,n) {
        b[t[i]-'a']++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a == b) {
        puts("Yes");
    } else {
        puts("No");
    }
}