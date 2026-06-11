#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

int a[600][600];
int p[600][600];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    int maxx=0;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        maxx=max(maxx,r);
        a[l][r]++;
    }

    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxx;j++){
            p[i][j]=p[i][j-1]+a[i][j];
        }
    }

    while(q--){
        int a,b;cin>>a>>b;
        int ans=0;
        for(int i=a;i<=b;i++){
            ans+=p[i][b];
        }
        cout<<ans<<endl;
    }
    return 0;
}
