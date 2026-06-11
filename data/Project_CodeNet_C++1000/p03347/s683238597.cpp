#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,next,p=1;
    long long n,sum=0;
    cin>>n;cin>>x;
    if(x!=0){p=0;}
    for(int i=1;i<n;i++){
        cin>>next;
        if(next-x>1){p=0;}
        else if(next-x==1){sum++;}
        else{sum+=next;}
        x=next;
    }
    if(p){cout<<sum<<endl;}
    else {cout<<"-1"<<endl;}
    return 0;
}

