#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A), t(B);
    for(int i = 0; i < A; i++) cin >> s[i];
    for(int i = 0; i < B; i++) cin >> t[i];
    for(int i = 0; i < Q; i++){
        long long x;
        cin >> x;
        auto ite = lower_bound(s.begin(), s.end(), x);
        long long ans = 1e18;
        if(ite != s.end()){
            long long res = 0;
            res += abs(*ite - x);
            auto ite2 = lower_bound(t.begin(), t.end(), *ite);
            long long temp = 1e18;
            if(ite2 != t.end()) temp = min(abs(*ite2 - *ite), temp);
            if(ite2 != t.begin()) temp = min(temp, abs(*(ite2 - 1) - *ite));
            ans = min(res + temp, ans);
        }
        if(ite != s.begin()){
            long long res = 0;
            res += abs(*(ite - 1) - x);
            long long y = *(ite - 1);
            auto ite2 = lower_bound(t.begin(), t.end(), y);
            long long temp = 1e18;
            if(ite2 != t.end()) temp = min(abs(*ite2 - y), temp);
            if(ite2 != t.begin()) temp = min(abs(*(ite2 - 1) - y), temp);
            ans = min(res + temp, ans);
        }
        auto ite3 = lower_bound(t.begin(), t.end(), x);
        if(ite3 != t.end()){
            long long res = 0;
            res += *ite3 - x;
            auto ite2 = lower_bound(s.begin(), s.end(), *ite3);
            long long temp = 1e18;
            if(ite2 != s.end()) temp = min(abs(*ite2 - *ite3), temp);
            if(ite2 != s.begin()) temp = min(temp, abs(*(ite2 - 1) - *ite3));
            ans = min(res + temp, ans);
        }
        if(ite3 != t.begin()){
            long long res = 0;
            res += abs(*(ite3 - 1) - x);
            long long y = *(ite3 - 1);
            auto ite2 = lower_bound(s.begin(), s.end(), y);
            long long temp = 1e18;
            if(ite2 != s.end()) temp = min(abs(*ite2 - y), temp);
            if(ite2 != s.begin()) temp = min(abs(*(ite2 - 1) - y), temp);
            ans = min(res + temp, ans);
        }
        cout << ans << endl;
    }
}