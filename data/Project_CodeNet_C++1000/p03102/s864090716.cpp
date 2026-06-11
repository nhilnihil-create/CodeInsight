#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> Bj(M);
    for(int j=0; j<M; j++){
        cin >> Bj.at(j);
    }

    vector<vector<int>> Aij(N, vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> Aij.at(i).at(j);
        }
    }

    int count = 0;
    for(int i=0; i<N; i++){
        int val = 0;
        for(int j=0; j<M; j++){
            val += Aij.at(i).at(j) * Bj.at(j);
        }
        val += C;
        if (val > 0){
            count += 1;
        }
    }

    cout << count;
    return 0;
}