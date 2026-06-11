#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>d(3);
    d[0]=a; d[1]=b; d[2]=c;
    sort(d.begin(),d.end());
    int cnt=0;
    int sa1=d[1]-d[0];
    int sa2=d[2]-d[1];
    if(sa1%2==0){
        rep(i,1000){
            sa1-=2;
            if(sa1>=0)cnt+=1;
            else break;
        }
        cnt+=sa2;
        cout<<cnt<<endl;
        return 0;
    }
    else{
        cnt+=1;
        sa1+=1;
        rep(i,1000){
            sa1-=2;
            if(sa1>=0)cnt+=1;
            else break;
        }
        cnt+=sa2;
        cout<<cnt<<endl;
        return 0;
    }
}
