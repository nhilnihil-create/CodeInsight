#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        int c,t;
        cin>>c>>t;
        p[i]=make_pair(c,t);
    }

    int ans=1e9;
    for(int i=0;i<n;i++){
        if(p[i].second<=t){
            ans=min(ans,p[i].first);
        }
    }
    if(ans==1e9) cout<<"TLE"<<endl;
    else cout<<ans<<endl;
}