#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    while(cin >> N){
        vector<int> A(1<<N);
        vector<vector<int>> maxA(1 << N, vector<int>(2, 0));
        for(auto& t : A) cin >> t;
        for(int i=1;i<(1<<N);i++){
            vector<int> idx;
            idx.push_back(i);
            for(int j=0;j<N;j++){
                if(i&(1<<j)){
                    for(int k=0;k<2;k++) idx.push_back(maxA[i^(1<<j)][k]);
                }
            }
            sort(idx.begin(), idx.end(), [&](int a, int b){return A[a] != A[b] ? A[a] > A[b] : a > b;});
            idx.erase(unique(idx.begin(), idx.end()), idx.end());
            for(int j=0;j<2;j++) maxA[i][j] = idx[j];
        }
        int res = 0;
        for(int i=1;i<(1<<N);i++){
            res = max(res, A[maxA[i][0]] + A[maxA[i][1]]);
            cout << res << endl;
        }
    }
}