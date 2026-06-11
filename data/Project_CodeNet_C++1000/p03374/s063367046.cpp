#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

ll A[N],X[N],M[N],n,k,i,p,a,x,ans;

int main(){
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld%lld",&x,&a);
        X[i] = x;
        A[i] = a;
    }

    p = 0;
    for(i=1;i<n;i++){
        p += A[i];
        M[n-i] = p - X[i]*2;
    }

    for(i=n-1; i ;i--) M[i] = max(M[i] , M[i+1]);

    p = 0;
    for(i=n; i ;i--){
        p += A[i];
        ans = max(ans , p + X[i]-k + M[n-i+1]);
    }
    //////
    p = 0;
    for(i=n; i>1 ;i--){
        p += A[i];
        M[i-1] = p - (k-X[i])*2;
    }

    for(i=n-1; i ;i--) M[i] = max(M[i] , M[i+1]);

    p = 0;
    for(i=1;i<=n;i++){
        p += A[i];
        ans = max(ans , p - X[i] + M[i]);
    }

    cout << ans;
    return 0;
}