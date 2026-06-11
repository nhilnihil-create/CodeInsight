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
    string S;
    cin >> S;
    int N = S.size();
    string S_1;
    string S_2;
    for(int i = 0; i < N; i++){
        if(i % 2) {
            S_1.push_back('0');
            S_2.push_back('1');
        }
        else {
            S_1.push_back('1');
            S_2.push_back('0');
        }
    }
    int one_n = 0, two_n = 0;
    for(int i = 0; i < N; i++){
        if(S[i] != S_1[i]) one_n++;
        if(S[i] != S_2[i]) two_n++;
    }
    cout << min(one_n, two_n) << endl;
}