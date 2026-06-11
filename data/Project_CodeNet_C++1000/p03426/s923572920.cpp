#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int a[305][305],l[100010],r[100010],ax[305*305],ay[305*305],sum[305*305];

int main(){
    int h,w,d;
    cin>>h>>w>>d;
    rep(i,h)rep(j,w){
        cin>>a[i][j];
        a[i][j]--;
        ay[a[i][j]]=i;
        ax[a[i][j]]=j;
    }
    int q;
    cin>>q;
    rep(i,q){
        cin>>l[i]>>r[i];
        l[i]--; r[i]--;
    }
    for(int i=h*w-1; i>=0; --i){
        if(i+d>=h*w)continue;
        sum[i]=sum[i+d]+(abs(ay[i]-ay[i+d])+abs(ax[i]-ax[i+d]));
    }
    rep(i,q){
        cout<<sum[l[i]]-sum[r[i]]<<endl;
    }
}