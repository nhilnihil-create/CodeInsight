#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int S = 0;
    for(int i=0; i<N; i++) S += A[i];
    int hS = S/2;
    bitset<2000*2000> knapsack;
    
    knapsack[0] = 1;
    for(int i=0; i<N; i++){
        knapsack = knapsack | (knapsack << A[i]);
    }

    int highest_true = 0;
    for(int i=1; i<=hS; i++){
        if(knapsack[i]) highest_true = i;
    }

    cout << S - highest_true << endl;
}
