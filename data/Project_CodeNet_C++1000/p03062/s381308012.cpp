#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)

int N;
int A[100010];
bool ex_zero;
int neg_n;

signed main()
{
    cin >> N;
    rep(i, N)
    {
        cin >> A[i];
        if(A[i] == 0)ex_zero = true;
        if(A[i] < 0)neg_n++;
    }

    int ans = 0;
    
    if(ex_zero || neg_n % 2 == 0)
    {
        rep(i, N) ans += abs(A[i]);
        cout << ans << endl;
        return 0;
    }

    rep(i, N) A[i] = abs(A[i]);
    sort(A, A + N);
    rep(i,N)
    {
        if(i == 0)ans -= A[i];
        else ans += A[i];
    }

    cout << ans << endl;
    return 0;
}