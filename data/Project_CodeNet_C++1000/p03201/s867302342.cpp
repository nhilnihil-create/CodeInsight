#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N; cin >> N;
    multiset<Int> S;
    rep(i,N){
        Int A; cin >> A;
        S.insert(A);
    }

    vector<Int> pow2 = {2};
    rep(i,30) pow2.push_back(pow2.back() * 2);

    int ans = 0;
    while(!S.empty()){
        Int now = *(--S.end()); 
        S.erase(--S.end());

        rep(j,31){
            auto it = S.find(pow2[j] - now);
            if(it != S.end()) {
                ans++;
                S.erase(it);
                break;
            }
        }
        cout << endl;
    }
    
    cout << ans << endl;
}
