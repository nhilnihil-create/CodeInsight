#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int dX=x2-x1,dY=y2-y1,x3,y3,x4,y4;
    y3=y2+dX;x3=x2-dY;
    x4=x3-dX;y4=y3-dY;
    
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}