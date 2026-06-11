#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N;
    cin >> N;

    vector<int> inputs(N);
    rep(i, N){
        cin >> inputs.at(i);
    }
    int min_n = inputs.at(0);
    int max_n = inputs.at(0);
    rep(i, N){
        int x = inputs.at(i);
        if(x < min_n) min_n = x;
        if(x > max_n) max_n = x;
    }
    cout << max_n - min_n << endl;
}