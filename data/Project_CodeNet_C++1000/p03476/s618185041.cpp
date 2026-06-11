#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;


int n,m;

int vis[N];

void A()
{
    for(int i=2;i<=1e5;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0 ) {
                vis[i]=1;
                break;
            }
        }
    }
}

int sum[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    A();
    vis[1]=1;

    for(int i=1e5;i>=1;i--){
         if(vis[i]==0 && vis[(i+1)/2]==1) vis[i]=1;
    }
    vis[2]=1;
    for(int i=1;i<=1e5;i++){
          sum[i]=sum[i-1];
          if(vis[i]==0) sum[i]++;
      //   cout<<sum[i]<<" ";
    }
  // cout<<endl;
    int q;cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }

    return 0;
}
