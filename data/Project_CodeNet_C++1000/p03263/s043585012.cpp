
// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>vec[i][j];

    // vector<pair<int, int>> odds;
    vector<vector<int>> store;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(vec[i][j]&1 && j != m-1){
                store.push_back({i, j, i, j+1});
                --vec[i][j];
                ++vec[i][j+1];
            }
        }
        for(int i = 0; i < n; i++){
            if(vec[i][m-1]&1 && i != n-1){
                store.push_back({i, m-1, i+1, m-1});
                --vec[i][m-1];
                ++vec[i+1][m-1];
            }
        }
/*

    for(int i = 1; i < odds.size(); i += 2){
        pair<int, int> fst = odds[i-1], snd = odds[i];
        if(fst.first == snd.first){
            while(snd.second != fst.second){
                store.push_back({fst.first, fst.second, fst.first, fst.second+1});
                ++fst.second;
            }
        }
        else{
            int d = 1;
            if(fst.second > snd.first)
                d = -1;
            while(snd.second != fst.second){
                store.push_back({fst.first, fst.second, fst.first, fst.second+d});
                fst.second += d;
            }
            while(snd.first != fst.first){
                store.push_back({fst.first, fst.second, fst.first+1, fst.second});
                ++fst.first;
            }
        }
    }*/
    cout<<store.size()<<"\n";
    for(auto itr : store){
        cout<<itr[0]+1<<" "<<itr[1]+1<<" "<<itr[2]+1<<" "<<itr[3]+1<<"\n";
        // cout<<"\n";
    }
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}
