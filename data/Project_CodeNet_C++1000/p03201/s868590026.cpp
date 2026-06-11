#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N; cin >> N;
    multiset<long long> A;
    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        A.insert(a);
    }
    
    vector<long long> powers_of_two;
    long long tmp = 1;
    long long tmp_limit = 1e16;
    for (;tmp <= tmp_limit;) {
        powers_of_two.push_back(tmp);
        tmp *= 2;
    }
    
    int ans = 0;
    while (!A.empty()) {
        auto itr = A.end();
        itr--;
        long long key = -1;
        for (int i = 0; powers_of_two[i] <= (*itr)*2; i++) {
            if (*itr < powers_of_two[i]) {
                key = powers_of_two[i];
            }
        }
        key = key - *itr;
        auto itr2 = A.lower_bound(key);
        if (itr2 != A.end() && *itr2 == key && itr2 != itr) {
            ans++;
            A.erase(itr2);
        }
        A.erase(itr);
    }
    cout << ans << endl;
}
