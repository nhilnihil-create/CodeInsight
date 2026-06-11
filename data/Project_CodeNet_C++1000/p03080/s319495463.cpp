#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    //s.size()=N;
    int cr = 0,cb = 0;
    rep(i,N)
        if(s[i]=='R') cr++;
        else cb++;
    if (cr>cb) cout << "Yes";
    else cout << "No";
}