#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <functional>
#include <deque>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int n,m;
    cin >> n >> m;

    map<ll,int> cnt;

    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        a[i] %= m;
    }

    for(int i = 1;i < n;i++)a[i] = (a[i] + a[i-1]) % m;

    ll ans = 0;
    for(int i = 0;i < n;i++){
        ans += cnt[a[i]]; 
        if(a[i] == 0)ans++;
        cnt[a[i]]++;
    }

    cout << ans << endl;
}
