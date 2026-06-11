#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(N) for (int i = 0; i < N; i++)

int main(){
    int N;
    cin >> N;
    int both_open, profit, max_profit;
    bitset<10> combination;
    vector<vector<int>> F(N, vector<int>(10));
    vector<vector<int>> P(N, vector<int>(11));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10; j++){
            cin >> F[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 11; j++){
            cin >> P[i][j];
        }
    }

    for (int i = 1; i < (1 << 10); i++){
        profit = 0;
        combination = i;
        for (int j = 0; j < N; j++){
            both_open = 0;
            for (int k = 0; k < 10; k++){
                if (combination[k] == 1 && F[j][k] == 1) both_open++;
            }
            profit += P[j][both_open];
        }
        if (i == 1) max_profit = profit;
        else{
            if (max_profit < profit) max_profit = profit;
        }
    }

    cout << max_profit << endl;
}
