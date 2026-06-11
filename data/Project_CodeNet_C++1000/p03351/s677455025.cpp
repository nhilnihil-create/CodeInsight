#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d=0;
    cin>>a>>b>>c>>d;
    int dis=abs(c-a);
    int dis1=abs(b-a);
    int dis2=abs(c-b);
    if(dis<=d){
        cout<<"Yes";
    }
    else if(dis>d&&dis1<=d&&dis2<=d){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}