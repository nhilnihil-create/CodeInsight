#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;

int main(){
    int n,t;
    cin>>n>>t;
    int ans=10000;
    rep(i,n){
        int c,s;
        cin>>c>>s;
        if(s<=t){
            ans=min(c,ans);
        }
    }
    if(ans!=10000)cout<<ans<<endl;
    else cout<<"TLE"<<endl;
}
