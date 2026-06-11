#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b=a;
    sort(a.begin(),a.end());
    int x=a[n/2-1],y=a[n/2];

    for(int i = 0; i < n; i++) {
        if(b[i]<=x){
            cout << y << endl;
        }
        else{
            cout << x << endl;
        }
    }

    return 0;
}