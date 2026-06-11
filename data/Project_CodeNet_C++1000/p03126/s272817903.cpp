#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>

#define N_size 100000000000

using namespace std;

int main(){
    int N,M,rs=0;

    cin >> N >> M;

    vector<int> A(M);

    vector<int> fl(M);

    int k = 0;

    for(int i = 0;i < M;i++){
        fl.at(i) = 0;
    }

    for(int i = 0;i < N;i++){
        cin >> k;
        for(int j = 0;j < k;j++)
            cin >> A.at(j);
        
        for(int j = 0;j < k;j++){
            fl.at(A.at(j) - 1)++;
        }
    }

    for(int i = 0;i < M;i++){
        if(fl.at(i) == N)
            rs++;
    }

    cout << rs << endl;
}
