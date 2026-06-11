#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool yes=false;
    if(n%7==0 && n/7>=1){
        yes=true;
        cout<<"Yes"<<endl;
    }
    else if(n%4==0 && n/4>=1){
        yes=true;
        cout<<"Yes"<<endl;
    }
    else{
        for(int i=7;i<=n;i=i+7){
            int temp=n-i;
            if(temp%4==0 && temp/4>=1){
                yes=true;
                cout<<"Yes"<<endl;
                break;
            }
        }
    }
    if(yes==false){
        cout<<"No"<<endl;
    }

    return 0;
}
