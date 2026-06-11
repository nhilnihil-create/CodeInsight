#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,flag=0;

    cin>>a>>b;

    for(int i=1;i<4;i++){
        if((i*a*b)%2 == 0)
            flag = 0;
        else
            flag++;
    }

    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}