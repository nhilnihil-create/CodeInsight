#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int N, int K, double &ans){

    vector<int> x(N, 1);
    for(int n = 0; n != N; ++n){
        int tmp = n + 1;

        while(tmp*x.at(n) < K){
            x.at(n) *= 2;
        }
    }

    for(int i = 0; i != N; ++i){
        double tmp = 1.0/x.at(i);
        ans += tmp;
    }
    ans /= N;
}

int main(){

    int N, K;
    cin >> N >> K;

    double ans{};
    solver(N, K, ans);

    cout << fixed << setprecision(10);
    cout << ans << endl;
    
    return 0;
}