#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
ll mod=1e9+7;
using P=pair<int,int>;
struct op{int a,b,c,d;};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,h;cin>>n>>h;
    vector<int> a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    int maxi=0,tot=0;
    rep(i,n)if(maxi<a[i])maxi=a[i];
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(b[i]<maxi)break;
        h-=b[i];
        tot++;
        if(h<=0)break;
    }
    if(h>0)tot+=(h+maxi-1)/maxi;
    cout<<tot<<endl;
    return 0;
}
