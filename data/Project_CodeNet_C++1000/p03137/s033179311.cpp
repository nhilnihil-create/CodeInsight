#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector<int> X(M);
    for(int i = 0; i < M; i++){
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    if(N >= M){
        cout << 0 << endl;
    }
    else{
        vector<int> diffX(M - 1);
        for(int i = 0; i < M - 1; i++){
            diffX[i] = X[i + 1] - X[i];
        }

        sort(diffX.begin(), diffX.end(), greater<int>());

        int sum = accumulate(diffX.begin(), diffX.end(), 0);

        for(int i = 0; i < N - 1; i++){
            sum -= diffX[i];
        }

        cout << sum << endl;
    }

    return 0;
}