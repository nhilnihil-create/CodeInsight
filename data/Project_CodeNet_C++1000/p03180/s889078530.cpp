#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;

ll N;
vector<vector<ll>> V(17, vector<ll>(17));
vector<ll> DP;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> V[i][j];
        }
    }
    DP.resize(1<<N);
    for(int i = 0; i < (1<< N); i++){
        bitset<17> B = i;
        ll score = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                if(B[i] == 1 && B[j] == 1) score += V[i][j];
            }
        }
        DP[i] = score;
    }
    for(int i1 = 0; i1 < (1<<N); i1++){
        bitset<17> B = i1;
        ll cnt = B.count();
            for(int t = i1; t > 0; t = (t-1)&i1){
            //for(int t = (i1-1)&i1; t > 0; t = (t-1)&i1){
                DP[i1] = max(DP[i1], DP[t]+DP[i1-t]);
            }
    }
    cout << DP[(1<<N)-1] << endl;

}
