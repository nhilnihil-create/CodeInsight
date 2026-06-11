#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;

int n;
vector<int> c(1000),s(1000),f(1000);

void solve(int pla){
    int time=0;
    while(1){
        if(time<s[pla]){
            time=s[pla];
        }
        if(time%f[pla]){
            time+=f[pla]-time%f[pla];
        }
        time+=c[pla];
        pla++;
        if(pla==n-1) break;
    }
    cout<<time<<endl;
}

int main(){
    cin>>n;
    rep(i,n-1) cin>>c[i]>>s[i]>>f[i];
    rep(i,n-1) solve(i);
    cout<<"0"<<endl;
}