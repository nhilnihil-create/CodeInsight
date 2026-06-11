
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans = 0;
    cin >> n;
    
    vector <int> mochis(n);
    for (int i = 0; i < n; i++) {
        cin >> mochis.at(i);
    }
    sort(mochis.begin(), mochis.end());

    int just_before = 0;

    for (int i = 0; i < n; i++) {
        if (mochis.at(i) != just_before) {
            ans++;
            just_before = mochis.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}
