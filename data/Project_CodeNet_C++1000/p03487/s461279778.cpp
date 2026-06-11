#include<iostream>
#include<map>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
    }

    int ans = 0;
    for (auto u:mp) {
        if(u.second >= u.first) ans += u.second - u.first;
        else ans += u.second;
    }

    cout << ans << endl;
}