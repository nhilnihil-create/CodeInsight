#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    if(n%k == 0)cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
