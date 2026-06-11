#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> vec(N, vector<ll>(2));
    for(int i = 0; i < N; i++){
        cin >> vec.at(i).at(0);
        cin >> vec.at(i).at(1);
    }
    sort(vec.begin(), vec.end());
    ll B = 0, cost = 0;
    for(int i = 0; i < N; i++){
        if(B + vec.at(i).at(1) >= M){
            cost += (M - B) * vec.at(i).at(0);
            cout << cost << endl;
            return 0;
        }
        B += vec.at(i).at(1);
        cost += vec.at(i).at(0) * vec.at(i).at(1);
    }

}