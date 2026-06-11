#include <bits/stdc++.h>
using namespace std;
#define rep(i, N)  for (int i = 0; i < (N); i++)

int main(){

    int N;
    cin >> N;
    vector<int> b(N);
    rep (i, N) cin >> b[i];

    vector<int> ans;
    rep (i, N){
        for (int j = b.size(); j != 0; j--){
            if (j == b[j-1]){
                ans.push_back(j);
                b.erase(b.begin()+j-1);
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    if (ans.size() == N) rep (i, N) cout << ans[i] << endl;
    else cout << "-1" << endl;

    return 0;
}