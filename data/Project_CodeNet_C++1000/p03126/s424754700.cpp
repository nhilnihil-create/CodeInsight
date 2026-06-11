#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,k;
ll b[35];
ll a[35][35];
ll ans;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a[i][j];
            b[a[i][j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i]==n){
            ans++;
        }
    }
    cout<<ans<<endl;

}

