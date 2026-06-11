#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 10005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll sumA = 0, sumB = 0, ans = 0;
int N, A[MAXN], B[MAXN];

void solve(){
    rep(i, N){
        if(A[i] < B[i]){
            ans += (B[i] - A[i])/2;
        } else if(A[i] > B[i]) {
            ans -= A[i] - B[i];
        }
    }

    if(ans < 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

int main(){
    cin >> N;

    rep(i, N){
        cin >> A[i];
        sumA += A[i];
    }

    rep(i, N){
        cin >> B[i];
        sumB += B[i];
    }

    solve();
}
