#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define INF 1<<30

int dp[1<<26];

int main(){
    fill_n(dp, 1<<26, INF);

    string s;
    cin >> s;
    int N = s.size();
    int bt = 0;
    for(int i=0; i<N; i++){
        int x = s[i] - 'a';
        bt ^= 1<<x;
        if(__builtin_popcount(bt)<=1){
            dp[bt] = 1;
            continue;
        }
        for(int j=0; j<26; j++)
            dp[bt] = min(dp[bt], dp[bt ^ (1<<j)] + 1);
    }
    cout << dp[bt] << endl;
    return 0;
}