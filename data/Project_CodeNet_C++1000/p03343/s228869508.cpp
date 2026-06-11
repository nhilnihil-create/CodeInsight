#include<bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;

#define eb(x) emplace_back(x)

const int N = 2010;
int a[N];
vector<int> v[N];

int main(){
    IOS;
    int n,k,q;cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0x3f3f3f3f;
    int cnt=1;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=cnt;j++)v[j].clear();
        int tar=a[i];
        cnt=1;
        vector<int> vv;
        for(int j=1;j<=n;j++){
            if(a[j]<tar){
                if(a[j-1]>=tar)cnt++;
                continue;
            }
            v[cnt].eb(a[j]);
        }
        for(int j=cnt;j>=1;j--){
            if(v[j].size()<k)continue;
            sort(v[j].begin(),v[j].end());
            for(int z=1;z<=(int)v[j].size()-k+1;z++)vv.eb(v[j][z-1]);
        }
        if((int)vv.size()>=q){
            sort(vv.begin(),vv.end());
            ans=min(ans,vv[q-1]-vv[0]);
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}