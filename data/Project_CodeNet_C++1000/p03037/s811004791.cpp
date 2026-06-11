#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vec(M, vector<int>(2));
    for(int i = 0; i < M; i++){
        cin >> vec.at(i).at(0) >> vec.at(i).at(1);
    }

    int ma = 1000000, mi = 1;
    for(int i = 0; i < M; i++){
        ma = min(ma, vec.at(i).at(1));
        mi = max(mi, vec.at(i).at(0));
    }

    int ans;
    if(mi <= ma){
        ans = ma - mi + 1;
    }
    else{
        ans = 0;
    }

    cout << ans << endl;
}