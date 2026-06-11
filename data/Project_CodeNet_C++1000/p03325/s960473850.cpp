#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int ans=0;;
    rep(i,n){
        rep(j,30){
            if(a[i]%2==0){
                ans+=1;
                a[i]/=2;
            }
            else break;
        }
    }
    cout<<ans<<endl;
}