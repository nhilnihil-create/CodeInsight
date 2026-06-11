#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N;
    cin >> N;
    vector<int> B(N);
    rep(i,N) cin >> B[i];
    vector<int> ans;

    for(int i = N; i > 0; i--){
        for(int j = i; j > 0; j--){
            if(j-1 >= B.size()) continue;
            if(B[j-1] == j){
                ans.emplace_back(j);
                B.erase(B.begin() + j-1);
                break;
            }
        }
    }
    if(B.size() != 0) cout << -1 << endl;
    else {
        reverse(all(ans));
        for(auto& a : ans) cout << a << endl;
    }
    
}

