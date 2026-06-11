#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A + 2);
    vector<long long> t(B + 2);
    long long INF = 1e18;
    s[0] = -INF;
    t[0] = -INF;
    for(int i = 0; i < A; i++) cin >> s[1 + i];
    s[A + 1] = INF;
    for(int i = 0; i < B; i++) cin >> t[1 + i];
    t[B + 1] = INF;
    for(int i = 0; i <Q; i++){
        long long x;
        cin >> x;
        int ind1 = lower_bound(s.begin(), s.end(), x) - s.begin();
        int ind2 = lower_bound(t.begin(), t.end(), x) - t.begin();
        long long ans = 1e18;
        for(int j = 0; j < 2; j++){
            long long y = s[ind1 - j];
            for(int k = 0; k < 2; k++){
                long long z = t[ind2 - k];
                long long d1 = abs(y - x) + abs(z - y), d2 = abs(z - x) + abs(y - z);
                ans = min(ans, min(d1, d2));
            }
        }
        cout << ans << endl;
    }
}