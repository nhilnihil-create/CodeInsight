//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    int n; cin>>n;
    vector<int>b(n);
    rep(i,n)cin>>b[i];
    vector<int>ans(n);
    int mx=0;
    bool jud=false;
    int cnt=0;
    rep(i,n){
        rep(j,b.size()){
               if(b[j]==j+1){
            mx=max(j,mx);
            jud=true;
        }
        }
        if(jud){
            b.erase(b.begin()+mx);
            ans[cnt]=mx+1;
            cnt++;
            mx=0;
            jud=false;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    rep(i,n){
        cout<<ans[i]<<endl;
    }
}






