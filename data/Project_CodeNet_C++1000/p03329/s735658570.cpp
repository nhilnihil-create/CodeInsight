#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> memo;
int dfs(int N){
    if(N == 0) return 0;
    if(N < 6) return memo[N] = dfs(N - 1) + 1;
    if(memo[N] != 1e9) return memo[N];
    int i = 9;
    int res = 1e9;
    while(N >= i){
        res = min(res, dfs(N - i) + 1);
        i *= 9;
    }
    int j = 6;
    while(N >= j){
        res = min(res, dfs(N - j) + 1);
        j *= 6;
    }
    return memo[N] = res;
}
int main(){
    cin >> N;
    int cnt = 0;
    memo.resize(N + 1, 1e9);
    cout << dfs(N) << endl;
}