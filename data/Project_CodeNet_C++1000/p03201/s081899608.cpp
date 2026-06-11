#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int N;
    cin >> N;
    ll a[N];
    map<ll, int> mp;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        mp[a[i]] ++;
    }

    sort(a, a + N);

    int ans = 0;

    for(int i = N - 1; i >= 0; i--){
        if(mp[a[i]] == 0) continue;

        mp[a[i]]--;
        ll x = 1;
        while(x <= a[i]) x *= 2;

        ll y = x - a[i];
        if(mp[y] > 0){
            //cout << a[i] << y << endl;
            ans++;
            mp[y] --;
        }
        else {
            mp[a[i]]++;
        }
    }

    cout << ans << endl;
    return 0;
}