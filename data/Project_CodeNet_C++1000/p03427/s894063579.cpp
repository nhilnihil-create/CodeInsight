#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string n; cin >> n;
    int ans = (n[0] - '0') - 1;
    ans += 9 * (n.size()-1);
    int uku = 0;
    for(int i=0;i<n.size();i++){
        uku += (n[i]-'0');
    }
    ans = max(ans,uku);
    cout << ans << endl;
    return 0;
}