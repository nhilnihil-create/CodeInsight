#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    map<char,ull> M;
    for(string s : S){
        M[s[0]]++;
    }
    vector<ull> A;
    for(char m : {'M', 'A', 'R', 'C', 'H'}){
        A.push_back(M[m]);
    }
    int n = A.size();
    ull ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                ans += A[i] * A[j] * A[k];
            }
        }
    }
    cout << ans << endl;
}