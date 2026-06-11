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
    int p[n];

    rep(i,n)cin>>p[i];

    map<int,int>next;
    rep(i,n){
        auto it=next.find(p[i]);
        if(it==next.end()){
            next.emplace(make_pair(p[i]+1,1));
        }
        else{
            int num=it->second;
            num++;
            next.erase(it);
            next.emplace(make_pair(p[i]+1,num));
        }
    }
    auto iter=next.begin();
    int k=-1;
    while(iter!=next.end()){
        k=max(k,iter->second);
        iter++;
    }
    //cout<<endl;
    cout<<n-k<<endl;
    return 0;

}
/*


*/
