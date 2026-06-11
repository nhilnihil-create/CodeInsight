#include <bits/stdc++.h>
using namespace std;
int x[1005],y[1005];
vector<int>d;
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        if((x[i]+y[i]-x[1]-y[1])%2)
            puts("-1"),exit(0);
    if((x[1]+y[1])%2==0)d.push_back(1);
    for(int i=30;~i;i--)d.push_back(1<<i);
    cout<<d.size()<<"\n";
    for(int i:d)cout<<i<<" ";cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int w:d)
            if(abs(x[i])>abs(y[i]))
                if(x[i]<0)x[i]+=w,cout<<"L";
                else x[i]-=w,cout<<"R";
            else
                if(y[i]<0)y[i]+=w,cout<<"D";
                else y[i]-=w,cout<<"U";
        cout<<"\n";
    }
    return 0;
}