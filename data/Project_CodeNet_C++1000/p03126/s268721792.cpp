#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m, 0);
    for(int i=0; i<n; ++i){
        int k; cin >> k;
        for(int j=0; j<k; ++j){
            int A; cin >> A; --A;
            ++cnt[A];
        }
    }
    int res = 0;
    for(int i=0; i<m; i++){
        if(cnt[i] == n){
            res++;
        }
    }

    cout << res << endl;
    return 0;
}