#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
using namespace std;

void zeta_transform(int N, vector<pair<int, int>> &f){
    for(int i=0; i<N; i++)
        for(int j=0; j<(1<<N); j++)
            if(j&(1<<i)){
                vector<int> hoge = {f[j].first, f[j].second, f[j^(1<<i)].first, f[j^(1<<i)].second};
                sort(hoge.begin(), hoge.end());
                f[j].first = hoge[3];
                f[j].second = hoge[2];
            }
}

int main(){
    int N;
    cin >> N;
    int M = 1<<N;
    vector<int> A(M);
    for(int i=0; i<M; i++)
        cin >> A[i];

    vector<pair<int, int>> B(M);
    for(int i=0; i<M; i++)
        B[i].first = A[i];

    zeta_transform(N, B);

    vector<int> C(M);
    for(int i=1; i<M; i++)
        C[i] = B[i].first + B[i].second;

    for(int i=1; i<M; i++)
        C[i] = max(C[i], C[i-1]);
    for(int i=1; i<M; i++)
        cout << C[i] << endl;

    return 0;
}
