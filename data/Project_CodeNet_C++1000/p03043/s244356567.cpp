#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int N, K;
    cin >> N >> K;
    double prob = 0;
    for(int x = 1; x <= N; x++){
        int n = ceil(log2(K) - log2(x));
        double win = 0;
        if(n > 0){
            win = 1.0 / (1 << n);
        }

        prob += win;
    }

    double result = 1.0/N * prob + max(0.0, (N - K + 1.0)/N);

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}
