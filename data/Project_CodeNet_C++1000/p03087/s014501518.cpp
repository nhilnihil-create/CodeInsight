#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<int> a(n);
    for(int i = 0; i < n-1; i++) {
        if(s[i]=='A' && s[i+1]=='C') a[i]=1;
    }

    vector<int> b(n+1);
    b[0]=0;
    for(int i = 1; i < n+1; i++) {
        b[i] = b[i-1]+a[i-1];
    }

    for(int i = 0; i < q; i++) {
        int l,r;
        cin >> l >> r;
        if(r==n){
            cout << b[r]-b[l-1] << endl;
            continue;
        }
        if(a[r-1]==1){
            cout << b[r]-b[l-1]-1 << endl;
        }
        else{
            cout << b[r]-b[l-1] << endl;
        }

    }

    return 0;
}