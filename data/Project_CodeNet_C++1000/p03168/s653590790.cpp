#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numCoins;
    cin >> numCoins;
    vector<double> pHeads(numCoins);
    for(double& coin : pHeads) {
        cin >> coin;
    }

    int nTails = (numCoins - 1)/2;
    vector<vector<double> > memo(numCoins, vector<double>(nTails+1, 0));

	memo[0][0] = pHeads[0];
    memo[0][1] = 1-pHeads[0];
    for(int i = 1; i < numCoins; i++) memo[i][0] = pHeads[i] * memo[i-1][0];

    for(int coin = 1; coin < numCoins; coin++) {
        for(int numTails = 1; numTails <= min(nTails, coin+1); numTails++) {
            memo[coin][numTails] = pHeads[coin] * memo[coin-1][numTails]
                                    + (1-pHeads[coin]) * memo[coin-1][numTails-1];
        }
    }

    double result = 0;
    for(double num : memo[numCoins-1]) result += num;

    printf("%.15f", result);

    return 0;
}