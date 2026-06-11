#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n,k,m;
    cin>>n>>k;k--;
    rep(i,n){
        if(m==1) continue;
        int a;
        cin>>a;
        if(a==1){
            m=i;
        }
    }
    int ans=(m-1)/k+((m-1)%k!=0);
    n-=(m-1)%k;
    ans+=(n-m)/k+((n-m)%k!=0);
    cout<<ans<<endl;
    return 0;
}
