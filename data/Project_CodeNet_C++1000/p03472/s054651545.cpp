#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,H; cin>>N>>H;
    int a[N],b[N];
    rep(i,N)cin>>a[i]>>b[i];
    sort(a,a+N);
    sort(b,b+N);
    int cnt=0;
    rep(i,N){
        if(a[N-1]<=b[i])cnt++;
    }
    int ans=0;
    int i=1;
    do{
        H-=b[N-i];
        i++;
        ans++;
    }while(H>0&&i<=cnt);
    if(H<=0){
        cout<<ans<<endl;
        return 0;
    }
    else{
        int c=H/a[N-1];
        if(H%a[N-1]==0)ans+=c;
        else ans+=(c+1);
    }
    cout<<ans<<endl;
    return 0;
}