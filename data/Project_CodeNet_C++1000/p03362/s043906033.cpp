#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int x;
    cin>>x;
    int n=2;
    vector<int>ans;
    while(ans.size()<x){
        bool ng=false;
        for(int j=2; j<=sqrt(n); ++j){
            if(n%j==0)ng=true;
        }
        if(!ng)if(n%5==1)ans.push_back(n);
        n++;
    }
    rep(i,x)cout<<ans[i]<<" ";
}