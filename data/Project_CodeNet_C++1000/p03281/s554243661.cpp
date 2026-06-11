#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int solve(int n){
    int ans=1;
    vector<int> cnt;
    for(int i=2;i*i<=n;i++){
        int tmp=0;
        while(n%i==0){
            n/=i;
            tmp++;
        }
        if(tmp!=0) cnt.push_back(tmp+1);
    }
    if(n!=1) cnt.push_back(2);
    for(int x:cnt){
        ans*=x;
    }
    if(ans==8) return 1;
    else return 0;
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    rep(i,n){
        if((i+1)%2==0) continue;
        ans+=solve(i+1);
    }
    cout<<ans<<endl;
}