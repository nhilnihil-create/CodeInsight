#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    bool a[105];
    memset(a,0,sizeof a);
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        a[b]=true;
    }
    int ans1=0,ans2=0;
    for(int i=x;i<=n;i++){
        if(a[i] == true){
            ans1++;
        }
    }
    for(int i=1;i<=x;i++){
        if(a[i] == true){
            ans2++;
        }
    }
    cout<<min(ans1,ans2)<<endl;
    return(0);
}