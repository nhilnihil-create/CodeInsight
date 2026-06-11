#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<vector<int>>> F(n, vector<vector<int>>(5, vector<int>(2)));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 2; k++){
                cin >> F[i][j][k];
            }
        }
    }
    vector<vector<int>> P(n, vector<int>(11, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            cin >> P[i][j];
        }
    }

    long long maxProfit = -1000000000000000;

    // i個目のbit : i / 2曜日のi % 2時間に営業するかどうか
    for(int bit = 1; bit < (1 << 10); bit++){
        vector<int> c(n, 0);
        for(int i = 0; i < 10; i++){
            if(bit & (1 << i)){
                int yobi = i / 2;
                int zikan = i % 2;
                for(int k = 0; k < n; k++){
                    if(F[k][yobi][zikan] == 1){
                        c[k]++;
                    }
                }
            }
        }
        // 利益計算
        long long profit = 0;
        for(int k = 0; k < n; k++){
            profit += P[k][c[k]];
        }
        maxProfit = max(profit, maxProfit);
    }

    cout << maxProfit << endl;
    
    return 0;
}
