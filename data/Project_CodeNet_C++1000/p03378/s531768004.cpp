#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(m);
    rep(i,m) cin>>a[i];
    
    int i=0;
    int cnt=0;
    while(x>a[i]){
        cnt++;
        i++;
    }
    
    if(cnt>m-cnt) cout<<m-cnt<<endl;
    else cout<<cnt<<endl;
    return 0;
}