#include <bits/stdc++.h>
using namespace std;
const long int INF = 1e18 + 2;
long int getSum(int l, int r, vector<long int> &slimes) {
    long int s = 0;
    for (int index = l; index <= r; index++)
        s += slimes[index];
    return s;
}
int main() {
    long int n;
    cin>>n;
    vector<long int> slimes(n);
    for (long int index = 0; index < n; index++) {
        cin>>slimes[index];
    }
    long int minCost = 0;
    vector<vector<long int> > cost(n, vector<long int> (n, 0));
    for (int row = n-1; row >= 0; row--) {
        for (int col = row; col < n; col++) {
            if (row == col)
                cost[row][col] = 0;
            else {
                long int sum = getSum(row, col, slimes);
                cost[row][col] = INF;
                for (int mid = row; mid < col; mid++)
                    cost[row][col] = min (cost[row][col], cost[row][mid] + cost[mid+1][col] + sum);
            }
        }
    }
    cout<<cost[0][n-1]<<"\n";
    return 0;
}
