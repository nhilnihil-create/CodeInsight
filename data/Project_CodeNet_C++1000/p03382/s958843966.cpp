#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair < ll , ll > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

int A[N],n,i,mx,a,b;

main(){
    cin >> n;
    for(i=1;i<=n;i++) { cin >> A[i]; mx = max(A[i] , mx); }

    a = -mod;
    b = mod;
    for(i=1;i<=n;i++){
        if(A[i] <= mx/2) a = max(a , A[i]);
        else b = min(b , A[i]);
    }
    
    if(mx/2 - a <= b - (mx+1)/2) cout << mx << " " << a;
    else cout << mx << " " << b;
    return 0;
}