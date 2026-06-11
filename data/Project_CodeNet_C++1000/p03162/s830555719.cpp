#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numDays;
    cin >> numDays;
    vector<vector<int> > happiness(numDays, vector<int>(3));
    for(int i = 0; i < numDays; i++) {
        cin >> happiness[i][0];
        cin >> happiness[i][1];
        cin >> happiness[i][2];
    }

    vector<int> prevTotals(3, 0);
    vector<int> currentTotals(3);

    for(int i = 0; i < numDays; i++) {
        currentTotals[0] = max(prevTotals[1], prevTotals[2]) + happiness[i][0];
        currentTotals[1] = max(prevTotals[0], prevTotals[2]) + happiness[i][1];
        currentTotals[2] = max(prevTotals[0], prevTotals[1]) + happiness[i][2];
        prevTotals = currentTotals;
    }
    
    cout << *max_element(currentTotals.begin(), currentTotals.end());

    return 0;
}