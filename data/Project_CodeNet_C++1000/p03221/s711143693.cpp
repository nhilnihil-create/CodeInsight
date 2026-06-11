#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> d(N);
    for (int i=0;i<M;i++){
        int P, Y;
        cin >> P >> Y;
        P--;
        d[P].push_back(make_pair(Y,i));
    }
    for (int i=0;i<N;i++){
        if (d[i].size() != 0){
            sort(d[i].begin(),d[i].end());
        }
    }
    vector<pair<int,pair<int,int>>> ans;
    for (int i=0;i<N;i++){
        for (int j=0;j<d[i].size();j++){
            ans.push_back(make_pair(d[i][j].second,make_pair(i+1,j+1)));
        }
    }
    sort(ans.begin(),ans.end());
    for (auto x : ans){
        cout.fill('0');
        cout << setw(6) << x.second.first << setw(6) <<  x.second.second << "\n";
    }
    return 0;
}