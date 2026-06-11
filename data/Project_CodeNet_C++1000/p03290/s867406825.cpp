#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;


int n,m,cnt,ans=1e9;

int p[20],c[20],vis[20];

bool check(int sum)
{
    int  pos=0;
    for(int i=n;i>=1;i--) {
        if(!vis[i]) {
            pos=i;
            break;
        }
    }
    if(sum>=m) {
        return 1;
    }
    else {
        for(int i=1;i<p[pos];i++){
            sum+=pos*100;
            cnt++;
            if(sum>=m) {
                return 1;
            }
        }
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>c[i];
    }

    for(int i=0;i<(1<<n);i++){
            int sum=0;
            cnt=0;
            memset(vis,0,sizeof vis);
        for(int j=0;j<n;j++){
            if(i & (1<<j)) {
                sum+=c[j+1]+(j+1)*p[j+1]*100;
                cnt+=p[j+1];
                vis[j+1]=1;
            }
        }
      //  cout<<i<<" "<<sum<<" "<<cnt<<endl;
        if(check(sum)) {
            //    cout<<cnt<<endl;
            ans=min(ans,cnt);
        }

    }
    cout<<ans<<endl;
    return 0;
}
