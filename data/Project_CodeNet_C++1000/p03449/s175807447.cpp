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
    vector<int> A1(N), A2(N);
    for(int i = 0; i < N; i++) cin >> A1[i];
    for(int i = 0; i < N; i++) cin >> A2[i];
    vector<int> sumA1(N), sumA2(N);
    sumA1[0] = A1[0];
    sumA2[0] = A2[0];
    for(int i = 1; i < N; i++){
        sumA1[i] = sumA1[i - 1] + A1[i];
        sumA2[i] = sumA2[i - 1] + A2[i];
    }
    ll max_n = 0;
    for(int turn = 0; turn < N; turn++){
        ll sum = 0;
        sum += sumA1[turn];
        if(turn == 0) sum += sumA2.back();
        else sum+= sumA2.back() - sumA2[turn - 1];
        max_n = max(max_n, sum);
    }
    cout << max_n << endl;
}