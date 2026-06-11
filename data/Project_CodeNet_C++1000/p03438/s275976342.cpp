#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int po=0;
    int ng=0;
    for(int i = 0; i < n; i++) {
        if(a[i]>b[i]) po+=(a[i]-b[i]);
        else ng+=((b[i]-a[i])/2);
    }
    if(ng<po) cout << "No" << "\n";
    else cout << "Yes" << "\n";

    return 0;
}