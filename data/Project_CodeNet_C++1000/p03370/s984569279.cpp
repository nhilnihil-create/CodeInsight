#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> m(n);
    int sum=0;
    rep(i,n){
        cin>>m[i];
        sum+=m[i];
    }
    sort(m.begin(),m.end());
    x-=sum;
    cout<<n+x/m[0]<<"\n";
    return 0;
}