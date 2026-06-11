#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    char y;
    cin >> y;
    if(y=='W') a[0]=1;
    for(int i = 1; i < n; i++) {
        char x;
        cin >> x;
        if(x=='W'){
            a[i]=a[i-1]+1;
        }
        else{
            a[i]=a[i-1];
        }
    }
    int nw=a[n-1],ne=n-nw;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i]=ne-(i+1-a[i]);
    }

    vector<int> c(n);
    c[0]=b[0];
    for(int i = 1; i < n; i++) {
        c[i]=a[i-1]+b[i];
    }

    sort(c.begin(),c.end());
    cout << c[0] << endl;

    return 0;
}