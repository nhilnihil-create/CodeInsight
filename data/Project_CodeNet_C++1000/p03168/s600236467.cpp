#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    
    int N = 0;
    cin >> N;
    int half = N/2;
    vector<vector<double> > probability(N + 1,vector<double>(N + 2,0));
    vector<double> coin(N,0);
    for(int i = 0; i < N; i++) {
        cin >> coin.at(i);
    }
    int temp;
    probability.at(0).at(1) = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N + 1; j++) {
            probability.at(i).at(j) = probability.at(i-1).at(j - 1)*coin.at(i - 1) + probability.at(i-1).at(j)*(1 - coin.at(i - 1));
        }
    }


    /*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N + 1; j++) {
            cout << probability.at(i + 1).at(j + 1) << ' ';
        }
        cout << endl;
    }
    */

    double ans;

    for(int i = 0; i <= half; i++) {
        //cout << ans << endl;
        ans += probability.at(N).at(N + 1 - i);
        //cout << probability.at(N).at(N + 1 - i) << endl;
        //cout << ans << endl;
    }

    cout << fixed << setprecision(10) << ans << endl;




    return 0;
}