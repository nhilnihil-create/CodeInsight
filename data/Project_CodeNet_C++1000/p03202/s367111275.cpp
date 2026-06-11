#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int l, r = N;
    l = max(0, (int)count(A.begin(), A.end(), 1)-1);
    while (r-l > 1) {
        int c = (19*l+r+18)/20;
        map<int, int> mp;
        for (int i = 1; i < N; i++) {
            if (A[i-1] >= A[i]) {
                if (c == 1) {
                    mp[0] = 1;
                    break;
                }
                int t = A[i];
                mp[t]++;
                auto it = mp.upper_bound(t);
                mp.erase(it, mp.end());
                while (t > 0 && mp[t] == c) {
                    mp[t] = 0;
                    mp[t-1]++;
                    t--;
                }
            }
            if (mp[0] > 0) break;
        }
        if (mp[0] == 0) r = c;
        else l = c;
    }
    cout << r << endl;
    return 0;
}
