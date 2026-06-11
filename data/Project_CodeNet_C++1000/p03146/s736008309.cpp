#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,ans=0;
    bool a[1000005];
    cin>>s;
    memset(a,0,sizeof a);
    while(true){
        a[s]=true;
        ans++;
        if(s%2==0){
            s/=2;
        }
        else{
            s=s*3+1;
        }
        if(a[s]==true){
            break;
        }
    }
    cout<<ans+1<<endl;
    return(0);
}