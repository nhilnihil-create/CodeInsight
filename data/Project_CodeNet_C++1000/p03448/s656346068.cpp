#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
using ll=long long;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    
    int x;
    cin>>x;
    
    vector<int> p(3);
    int ans=0;
    
    rep(i,a){
        rep(j,b){
            rep(k,c){
                if(500*i+100*j+50*k==x)ans++;
            }
        }
    }
    cout<<ans;
    
    
    return 0;
    }

