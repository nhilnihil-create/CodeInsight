#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    
    vector<int> A(N);
    vector<pair<int, int>> sa(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sa[i] = {A[i], i};
    }
    sort(sa.begin(), sa.end());
    vector<bool> use(N+1, true);
    use[N] = false;
    int ans = sa[Q-1].first - sa[0].first;
    
    for (int i = 0; i < N; i++) {
        vector<int> cand;
        multiset<int> box;
        for (int j = 0; j <= N; j++) {
            if (use[j]){
                box.insert(A[j]);
            }
            else {
                int t = box.size();
                auto it = box.begin();
                for (int k = 0; k < t-K+1; k++) {
                    cand.push_back(*it);
                    it++;
                }
                box.clear();
            }
        }
        if ((int)cand.size() >= Q) {
            sort(cand.begin(), cand.end());
            ans = min(ans, cand[Q-1]-cand[0]);
        }else break;
        
        use[sa[i].second] = false;
    }
    cout << ans << endl;
    return 0;
}