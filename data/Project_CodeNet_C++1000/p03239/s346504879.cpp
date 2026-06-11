#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,T;
    cin>>N>>T;
    int ans=1e8;
    int count=0;
    for(int i=0;i<N;i++){
        int c,t;
        cin>>c>>t;
        if(t<=T){
            ans=min(ans,c);
        }
        else count++;
    }
    if(count==N) cout<<"TLE"<<endl;
    else cout<<ans<<endl;
}