/*
    Problem 69
    https://atcoder.jp/contests/abc084/tasks/abc084_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 100005;
/* global variables */
vector<bool> isPrime;
vector<bool> isLike2017;
vector<int> prefixSum(MAX+1);
/* function */
void eratos() {
    isPrime.assign(MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j <= MAX; j+=i)
            isPrime[j] = false;
    }
}
void calcLike2017() {
    isLike2017.assign(MAX, false);
    for (int i = 1; i < MAX; i+=2) {
        if (isPrime[i] && isPrime[(i+1)/2]) isLike2017[i] = true;
    }
}
void fillPrefixSum () {
    for (int i = 0; i < MAX; i++)
        prefixSum[i+1] = prefixSum[i] + isLike2017[i];
}
int calcAns(int l, int r) {
    // [l, r)
    return prefixSum[r+1] - prefixSum[l];
}
/* main */
int main(){
    eratos();
    calcLike2017();
    fillPrefixSum();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << calcAns(l, r) << '\n';
    }
}