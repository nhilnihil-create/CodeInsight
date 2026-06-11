#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    long long L[100];
    L[0] = 2; L[1] = 1;
    for(int i=2;i<=n;++i) {
         L[i] = L[i-1] + L[i-2];
    }
    cout << L[n] << endl;
}
