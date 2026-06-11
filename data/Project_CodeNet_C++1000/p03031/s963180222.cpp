#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int n, m; cin >> n >> m;
    vector<int> bi(m), pi(m);
    int k, s, ans = 0;
    rep(i, m){
        cin >> k;
        bi[i] = 0;
        rep(j, k){
            cin >> s;
            bi[i] |= (1 << (s-1));
        }
    }
    rep(i, m){
        cin >> pi[i];
    }

    rep(b, (1 << n)){
        bool isAllOn = true;
        rep(i, m){
            if((bitset<12>((bi[i] & b)).count() % 2) != pi[i])
                isAllOn = false;
        }
        if(isAllOn) ans++;
    }

    cout << ans << endl;
    return 0;
}
