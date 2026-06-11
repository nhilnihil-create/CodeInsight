#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    vector<int> v[4];
    rep(i,2,30001){
        if(i % 6 == 0)v[0].push_back(i);
        if(i % 6 == 2)v[1].push_back(i);
        if(i % 6 == 3)v[2].push_back(i);
        if(i % 6 == 4)v[3].push_back(i);
    }
    rep(i,0,4)reverse(v[i].begin(), v[i].end());
    vector<int> ans;
    rep(i,0,N/2){
        if(i % 2 == 0 && v[1].size() && v[3].size()){
            ans.push_back(v[1].back());
            ans.push_back(v[3].back());
            v[1].pop_back();
            v[3].pop_back();
        }
        if(i % 2 == 1 && v[2].size() >= 2){
            rep(j,0,2){
                ans.push_back(v[2].back());
                v[2].pop_back();
            }
        }
    }
    while(N != ans.size()){
        ans.push_back(v[0].back());
        v[0].pop_back();
    }
    rep(i,0,N)cout << ans[i] << " ";
}