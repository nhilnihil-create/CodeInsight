#include <bits/stdc++.h>
using namespace std;
long int luca(int a,vector<long int> &memo){
    if(memo[a] != -1) return memo[a];
    if(a == 0){
        memo[a] = 2;
        return memo[a];
    }
    else if(a == 1){
        memo[a] = 1;
        return memo[a];
    }
    memo[a] = luca(a - 1, memo) + luca(a - 2, memo);
    return memo[a];
}
int main(){
    int N;
    cin >> N;
    vector<long int> memo(N + 1,-1);
    cout << luca(N,memo) << endl;
}