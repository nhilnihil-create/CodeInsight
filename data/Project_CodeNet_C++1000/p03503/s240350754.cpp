#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int sum,maxsum = INT_MIN;
    cin >> N;
    
    // 縦について全2^10通り試せば良い

    vector<vector<int>> shop(10,vector<int>(N));
    for(int i=0;i<N;i++) {
        for(int j=0;j<10;j++) {
            cin >> shop[j][i];
        }
    }

    vector<vector<int>> gain(11,vector<int>(N));
    for(int i=0;i<N;i++) {
        for(int j=0;j<11;j++) {
            cin >> gain[j][i];
        }
    }

    for(int i=1;i<(1<<10);i++) {
        vector<int> openshop(N,0);
        for(int j=0;j<10;j++) {
            if((i >> j)&1) {
                for(int k=0;k<N;k++) {
                    openshop[k] += shop[j][k];
                }
            }
        }
    
        sum = 0;
        for(int j=0;j<N;j++) {
            sum += gain[openshop[j]][j];
        }
        if(maxsum < sum) {
            maxsum = sum;
        }
    }

    cout << maxsum << endl;
    return 0;
}
