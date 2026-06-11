#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> sv;
    int cnt = 0;
    if ( s[0] == '0' ) sv.push_back(0);
    for ( int i = 0; i < s.size();) {
        int j = i;
        while(j<s.size() && s[j] == s[i] ) ++j;
        sv.push_back(j-i);
        i = j;
    }
    if ( s.back() == '0' ) sv.push_back(0);

    vector<int> sums(sv.size()+1, 0);
    rep(i, sv.size()) {
        sums[i+1] = sums[i] + sv[i];
    }

    int ans = 0;
    for ( int left = 0; left < sums.size(); left += 2 ) {
        int right = left + 2 * k + 1;
        if ( right >= sums.size() ) {
            right = (int)sums.size() - 1;
        }
        ans = max(ans, sums[right] - sums[left]);
    }
    cout << ans << endl;
    return 0;
}
