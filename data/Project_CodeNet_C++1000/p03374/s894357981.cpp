#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
double pi = 3.141592653589793;
using namespace std;
//ここから始めよう
signed main(){
    int n,c;cin>>n>>c;
    int x[114514],v[114514];
    int l[114514];int r[114514];
    l[0]=0,r[n]=0;
    rep(i,0,n){
        cin>>x[i]>>v[i];
    }
    int point=0;
    rep(i,1,n+1){
        point+=v[i-1];
        l[i]=point-x[i-1];
    }
    rep(i,1,n+1){
        l[i]=max(l[i-1],l[i]);
    }
    point=0;
    for(int i=n-1;i>=0;i--){
        point+=v[i];
        r[i]=point-c+x[i];
    }
    for(int i=n-1;i>=0;i--){
        r[i]=max(r[i+1],r[i]);
    }int ans=max(l[n],r[0]);
    for(int i=n;i>=0;i--){
        if(i==0){
            x[i]=0,v[i]=0;
        }
        else {
            x[i]=x[i-1]; v[i]=v[i-1];
        }
    }
    rep(i,0,n){
        ans=max(ans,l[i]+r[i]-min(x[i],c-x[i+1]));
    }
    cout<<ans<<endl;
    return 0;
}