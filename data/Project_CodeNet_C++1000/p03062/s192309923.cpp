#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N];

int32_t main(){
    fast;
    int n , c = 0; cin >> n ;
    for(int i = 0 ; i < n ;++i){
        cin >> A[i] ;
        if(A[i] < 0){
            c++;
            A[i] = -A[i];
        }
    }
    sort(A,A+n);
    int ans = 0;
    if(c%2==1) A[0] = -A[0];
    for(int i = 0; i < n ; ++i) ans += A[i];
    cout << ans << endl;
    return 0;
}