#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    int n;
    cin>>n;

    vector<long long> b(n);

    rep(i,n)cin>>b[i];

    vector<int>ans;

    while(b.size()>0){
        bool find=false;

        for(int i=b.size()-1;i>-1;i--){
            if(b[i]==i+1){
            ans.insert(ans.begin(),b[i]);
            find=true;
            b.erase(b.begin()+i);
            break;
            }
        }

        if(!find){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    rep(i,n)cout<<ans[i]<<endl;

    return 0;

}
/*


*/
