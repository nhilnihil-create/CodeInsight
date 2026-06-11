#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,s1,s2,s3;
    cin>>a>>b>>c>>d;
    s1=abs(a-b);
    s2=abs(a-c);
    s3=abs(b-c);
    if(s2<=d){
        cout<<"Yes";
    }
    else{
        if(s1<=d &&  s3<=d){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
}
