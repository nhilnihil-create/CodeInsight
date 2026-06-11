#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    ans += abs(a[0]);
    ans += abs(a[n-1]);
    for(int i = 0; i < n-1; i++)
        ans += abs(a[i+1]-a[i]);
    ll fans = ans;
    fans -= abs(a[0])+abs(a[0]-a[1]);
    fans += abs(a[1]);
    cout << fans << endl;
    for(int i = 1; i < n-1; i++){
        fans = ans;
        fans -= abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
        fans += abs(a[i+1]-a[i-1]);
        cout << fans << endl;
    }
    fans = ans;
    fans -= abs(a[n-1])+abs(a[n-1]-a[n-2]);
    fans += abs(a[n-2]);
    cout << fans << endl;
    return 0;
}