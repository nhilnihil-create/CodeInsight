#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N], D[N];

int32_t main()
{
    fast;
    int n , k ; cin >> n >> k;
    for(int i = 0 ;i < n ; ++i) cin >> A[i];
    int ans = 1e18;
    
    for(int i = 0 ; i < n-k+1 ; ++i){
        int l = i , r = i + k - 1;
        int a = min(abs(A[l]) , abs(A[r]));
        int b = A[r] - A[l];
        int s = a+b;
        ans = min(s,ans);
    }
    cout << ans << endl;
    return 0;
}