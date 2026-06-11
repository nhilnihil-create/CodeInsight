#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(int N, vector<int> &h, int &ans){

    int ans_buf = h.at(0);
    for(int i = 0; i != N-1; ++i){
        int dif_value{};
        dif_value = h.at(i+1) - h.at(i);

        if(dif_value > 0) ans_buf += dif_value;
    }
    ans = ans_buf;

    return;
}

int main(){

    int N;
    cin >> N;
    vector<int> h(N);
    for(int i = 0; i != N; ++i) cin >> h.at(i);

    int ans{};
    solver(N, h, ans);

    cout << ans << endl;
    return 0;
}