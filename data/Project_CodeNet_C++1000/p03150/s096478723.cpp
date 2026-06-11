#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    string n;
    cin>>n;
    bool f=false;
    if(n=="keyence"){
        cout<<"YES"<<endl;
        return 0;
    }
    long long j=n.size()-7;
    f(i,0,8){
        string ans=n.substr(0,i)+n.substr(i+j);
        if(ans=="keyence"){
            f=true;
            break;
        }
    }
    if(f){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
