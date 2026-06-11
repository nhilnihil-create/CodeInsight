#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N; cin >> N;
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<int> sorted_X(N);
    rep(i, N) sorted_X[i] = X[i];
    sort(sorted_X.begin(), sorted_X.end());
    int left_median = sorted_X[N/2-1];
    int right_median = sorted_X[N/2];
    rep(i, N){
        if(X[i] <= left_median){
            cout << right_median << endl;
        }else{
            cout << left_median << endl;
        }
    }
    return 0;
}
