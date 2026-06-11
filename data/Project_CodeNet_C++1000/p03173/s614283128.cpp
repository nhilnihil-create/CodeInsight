#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define forN(i, n) for(int i = 1; i <=n ; ++i)
#define endl "\n"
typedef long long ll;
using namespace std;
const ll INF = 1e18;

const int N = 405;
ll A[N],DP[N][N],prefix[N],n;

ll cost(int i ,int j){
    if(i-1>=0)return prefix[j]-prefix[i-1];
    return prefix[j];
}

ll calc(int L , int R){
    if (L == R)return 0;
    ll &ans  = DP[L][R];
    if(ans != -1)return ans;
    ans = INF;
    for(int k = L ; k<R+1 ; k++){
        ans = min(ans , calc(L,k) + calc(k+1,R) + cost(L,R));
    }
    return ans;
}

int main(){
    fastIO;
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>A[i];
        prefix[i] = A[i];
        if(i>0)prefix[i]+=prefix[i-1];
    }
    memset(DP,-1,sizeof DP);
    cout<<calc(0,n-1);
    return 0;
}
