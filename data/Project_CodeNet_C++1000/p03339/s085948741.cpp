#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, cnt, ans=300000;
    string s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    

    cnt=0;
    for(int i=0;i<n; i++) {
        a[i]=cnt;
        if(s.at(i)=='W') cnt++;
    }

    cnt=0;
    for(int i=n-1;i>=0; i--) {
        b[i]=cnt;
        if(s.at(i)=='E') cnt++;
    }

    for(int i=0; i<n; i++) {
        ans=min(ans, a[i]+b[i]);
    }

    cout << ans;
}