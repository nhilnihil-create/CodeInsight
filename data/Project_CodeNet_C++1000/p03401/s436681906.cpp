#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n;
    cin >> n;
    vector<int> A(n+2);
    A[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    A[n+1] = 0;

    int total = 0;
    for(int i=1; i<=n+1; i++){
        total += abs(A[i] - A[i-1]);
    }

    for(int i=1; i<=n; i++){
        int ans = total - abs(A[i+1] - A[i]) - abs(A[i] - A[i-1]);
        ans += abs(A[i+1] - A[i-1]);
        cout << ans << endl;
    }
    return 0;
}