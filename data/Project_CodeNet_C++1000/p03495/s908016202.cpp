#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,K,tmp,sum = 0;
    cin >> N >> K;

    vector<int> A(N);

    rep(i, N){
        cin >> tmp;
        A[tmp-1]++;
    }

    sort(A.begin(),A.end(),greater<int>());

    rep(i,K){
        sum += A[i];
    }

    cout << N-sum << endl;

    return 0;
}