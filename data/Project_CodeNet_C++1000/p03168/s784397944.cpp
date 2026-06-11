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
    vector<double> memo(nTails+1, 0);

    memo[0] = pHeads[0];
    memo[1] = 1-pHeads[0];

	for(int coin = 1; coin < numCoins; coin++) {
        double pre = memo[0];
        memo[0] = pHeads[coin] * memo[0];
        for(int numTails = 1; numTails <= min(nTails, coin+1); numTails++) {
            double tmp = memo[numTails];
            memo[numTails] = pHeads[coin] * memo[numTails]
                            + (1-pHeads[coin]) * pre;
            pre = tmp;
        }
    }
    
    double result = 0;
    for(double num : memo) result += num;
    printf("%.15f", result);

    return 0;
}