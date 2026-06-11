#include <iostream>
#include <vector>
using namespace std;

double getProbability(vector<double>& pHeads, int coin, int numTails, vector<vector<double> >& memo) {
    if(coin == pHeads.size()) return 1;
    if(memo[coin][numTails] != -1) return memo[coin][numTails];
    memo[coin][numTails] = pHeads[coin] * getProbability(pHeads, coin+1, numTails, memo);
    if(numTails > 0) memo[coin][numTails] += (1 - pHeads[coin]) * getProbability(pHeads, coin+1, numTails-1, memo);
    
    return memo[coin][numTails];
}

int main() {
    int numCoins;
    cin >> numCoins;
    vector<double> pHeads(numCoins);
    for(double& coin : pHeads) {
        cin >> coin;
    }

    int numTails = (numCoins - 1)/2;
    vector<vector<double> > memo(numCoins, vector<double>(numTails+1, -1));
    printf("%.15f", getProbability(pHeads, 0, numTails, memo));

    return 0;
}