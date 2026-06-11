#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n, m;
    cin >> n >> m;
    int mn=0, mx=10000000;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;

        mx = min(mx, b);
        mn = max(mn, a);
    }

    cout << max(mx-mn+1, 0);
}