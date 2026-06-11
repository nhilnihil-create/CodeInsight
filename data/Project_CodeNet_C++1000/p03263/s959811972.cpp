#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w));
    vector<tuple<int, int, int, int>> ans;
    rep(i,h)rep(j,w) cin >> A[i][j];
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w-1; ++j){
            if(A[i][j] % 2 == 1){
                A[i][j]--;
                A[i][j+1]++;
                ans.push_back(make_tuple(i,j,i,j+1));
            }
        }
    }
    for(int i = 0; i < h-1; i++){
        if(A[i][w-1] % 2 == 1){
            A[i][w-1]--;
            A[i+1][w-1]++;
            ans.push_back(make_tuple(i, w-1, i+1, w-1));
        }
    }
    cout << ans.size() << endl;
    for(auto elem : ans){
        cout << get<0>(elem)+1 << " " << get<1>(elem)+1 << " " << get<2>(elem)+1 << " " << get<3>(elem)+1 << endl;
    }
}