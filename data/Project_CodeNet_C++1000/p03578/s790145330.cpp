#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main(){
    int N, D, M, T;
    cin >> N;
    multiset <int> S;
    while(N-- && cin >> D){
        S.insert(D);
    }
    cin >> M;
    while(cin >> T){
        if(!S.count(T)){
            cout << "NO" << endl;
            return 0;
        }
        S.erase(S.find(T));
    }
    cout << "YES" << endl;
}