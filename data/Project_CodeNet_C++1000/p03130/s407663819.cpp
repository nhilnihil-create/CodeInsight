#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> cnt(5, 0);
    for (int i = 0; i < 6; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    if (count(cnt.begin(), cnt.end(), 3) > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}