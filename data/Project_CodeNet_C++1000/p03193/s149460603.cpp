#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,h,w,x,y,ans=0;
    cin>>n>>h>>w;
    rep(i,n){
        cin>>x>>y;
        if(x>=h&&y>=w){
            ans++;
        }
    }
    cout<<ans<<endl;
}