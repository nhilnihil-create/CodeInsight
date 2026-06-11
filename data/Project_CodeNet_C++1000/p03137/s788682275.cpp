#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(int N, int M, vector<int> &X, int &ans){

    sort(X.begin(), X.end());

    vector<int> dif_vec;
    for(int i = 0; i != M-1; ++i){
        int dif = X.at(i+1) - X.at(i);
        dif_vec.push_back(dif);
    }

    sort(dif_vec.begin(), dif_vec.end());

    for(int i = 0; i != N-1; ++i){
        if(dif_vec.size()) dif_vec.pop_back();
    }

    int ans_buf{};
    for(size_t i = 0; i != dif_vec.size(); ++i){
        ans_buf += dif_vec.at(i);
    }

    ans = ans_buf;

    return;
}

int main(){

    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for(int i = 0; i != M; ++i) cin >> X.at(i);

    int ans;
    solver(N, M, X, ans);

    cout << ans << endl;
    return 0;
}