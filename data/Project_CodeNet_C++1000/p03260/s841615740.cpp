#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c=0,i;
    cin>>a>>b;

    for(i=1;i<=3;i++){
        if((a*b*i)%2 != 0)
            c++;
    }
    if(c>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}