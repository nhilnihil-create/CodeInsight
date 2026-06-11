#include<bits/stdc++.h>
using namespace std;

int main(){
    int d;
    int n;
    cin>>d>>n;
    if(d==0 && n<100)cout<<n<<endl;
    else if(d==0 && n==100)cout<<101<<endl;
    else if(d==1 && n<100){
        cout<<100*n<<endl;
    }
    else if(d==2 && n<100){
        cout<<10000*n<<endl;

    }
    else if(d==1 & n==100){
        cout<<10100<<endl;
    }
    else if(d==2 && n==100){
        cout<<1010000<<endl;
    }
}