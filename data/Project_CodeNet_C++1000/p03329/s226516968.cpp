#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> memo1(n+1, 1001001001);
    vector<int> coins;
    coins.push_back(1);
    for(int i = 6; i <= n; i *= 6) coins.push_back(i);
    for(int i = 9; i <= n; i *= 9) coins.push_back(i);
    memo1[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < coins.size(); j++){
            if(i-coins[j] >= 0){
                if(memo1[i] > memo1[i-coins[j]]+1){
                    memo1[i] = memo1[i-coins[j]]+1;
                }
            }
        }
    }
    cout << memo1[n] << endl;
    return 0;
}