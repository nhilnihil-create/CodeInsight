#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int n;
ll a[3001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; sum += a[i];
    }
    cout << sum -n << endl;
    return 0;
}
