#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, M, A, B, C;
    string s1, s2;
    cin >> N;
    vector<pair<string, int>> res(N);
    rep(i, N){
        cin >> s1 >> A;
        res[i] = make_pair(s1, A * -1);
    }
    auto res_sorted = res;
    sort(all(res_sorted));
    for(auto x:res_sorted){
        rep(i, N){
            if(res[i].first == x.first && res[i].second == x.second) cout << i + 1 << endl;
        }
    }
} 