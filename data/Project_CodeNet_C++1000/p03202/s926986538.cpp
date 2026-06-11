#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
int n,a[N];map<int,int> mp;
bool check(int x){
    mp.clear();
    rep(i,1,n) if(a[i]<=a[i-1]){
        while(!mp.empty()){
            int x=mp.rbegin()->fi;
            if(x<=a[i]) break;mp.erase(x);
        }int p=a[i];
        while(mp[p]+1==x) mp.erase(p--);
        if(!p) return 0;mp[p]++;
    }
    return 1;
}
int main(){
    scanf("%d",&n);bool t=1;
    rep(i,1,n) scanf("%d",a+i),t&=a[i-1]<a[i];
    if(t) return puts("1"),0;
    int l=2,r=n-1,ans=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}