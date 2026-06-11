#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int64_t i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N; cin>>N;

    vector<int> ans;
    bool escape=false;
    rep(h,1,3501){
        rep(n,h,3501){
            int64_t v1=h*n*N, v2=4*h*n-n*N-h*N;
            if(v2>0 && v1%v2==0){
                int64_t w=v1/v2;
                ans.push_back(h);
                ans.push_back(n);
                ans.push_back(w);
                escape=true;
                break;
            }
                
            if(escape) break;
        }
        if(escape) break;
    }

    for(auto a:ans) cout<<a<<" ";
    cout<<endl;
}