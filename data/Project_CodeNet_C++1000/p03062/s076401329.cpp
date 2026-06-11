// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int minus = 0;
    ll sum = 0;
    rep(i, N){
        cin >> A[i];
        if (A[i] < 0){
            minus++;
            A[i] *= -1;
        }
        sum += A[i];
    }

    if(minus % 2 == 0){
        cout << sum << endl;
    } else {
        sort(all(A));
        sum -= 2 * A[0];
        cout << sum << endl;
    }

}