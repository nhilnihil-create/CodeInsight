#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);

int main(){
    int n; sc(n)
    vector<int> A(n), dp(n+1,0);
    for (int i = 0; i < n; i++) sc(A[i])
    int tmp = abs(A[0]) + abs(A[n - 1]), ans;
    for (int i = 0; i < n - 1; i++) tmp += abs(A[i+1] - A[i]);
    for (int i = 0; i < n; i++){
        ans = tmp;
        if (i == 0){
            ans -= abs(A[0]) + abs(A[1] - A[0]);
            ans += abs(A[1]);
        }else if (i == n - 1){
            ans -= abs(A[n-1]) + abs(A[n-1] - A[n-2]);
            ans += abs(A[n-2]);
        }else {
            ans -= abs(A[i+1] - A[i]) + abs(A[i] - A[i-1]);
            ans += abs(A[i+1] - A[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}