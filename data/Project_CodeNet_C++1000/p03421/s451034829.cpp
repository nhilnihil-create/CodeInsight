#include<bits/stdc++.h>
using namespace std;

using lint = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b;
    while(cin >> n >> a >> b){
        if(a + b - 1 > n || (lint)a * b < (lint)n){
            cout << -1 << '\n';
            continue;
        }

        set<int> st;
        for(int i = 1 ; i <= n ; ++i){
            st.insert(i);
        }

        vector<int> ans;
        for(int i = 0 ; i < a ; ++i){
            ans.emplace_back(n - a + i + 1);
            st.erase(ans.back());
        }

        for(int i = a ; i + b - 1 < n ; i += b - 1){
            for(int j = i ; j < i + b - 1 ; ++j){
                ans.emplace_back((i - a) + (b - 1) - (j - i));
                st.erase(ans.back());
            }
        }

        for(auto it = st.rbegin() ; it != st.rend() ; ++it){
            ans.emplace_back(*it);
        }

        for(int i = 0 ; i < n ; ++i){
            if(i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    cout << flush;

    return 0;
}