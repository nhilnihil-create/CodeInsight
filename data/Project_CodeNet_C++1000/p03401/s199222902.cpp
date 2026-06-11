#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0]=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i+1];
    }
    a[n+1]=0;

    int tl=0;
    for(int i = 0; i < n+1; i++) {
        tl+=abs(a[i+1]-a[i]);
    }

    int lend,leni;
    for(int i = 0; i < n; i++) {
        lend=abs(a[i+1]-a[i])+abs(a[i+2]-a[i+1]);
        leni=abs(a[i]-a[i+2]);
        cout << tl-lend+leni << "\n";
    }

    return 0;
}