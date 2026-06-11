#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll = long long;
using namespace std;


signed main() {
    int N, M;cin >> N >> M;
    vector<vector<int>> vec(N);
    for(int i = 0;i < M;i++){
        int a, b;cin >> a >> b;
        vec[b - 1].push_back(a - 1);
    }
    set<int> current;
    int ans = 0;
    for(int i = 0;i < N;i++){
        bool f = false;
        for(auto a : vec[i]){
            if(current.find(a) != current.end()){
                f = true;
            }
        }
        if(f){
            ans++;
            current.clear();
        }
        current.insert(i);
    }
    cout<<ans<<endl;
}
