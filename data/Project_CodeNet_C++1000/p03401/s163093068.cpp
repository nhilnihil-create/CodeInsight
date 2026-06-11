#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)(n);i++)
using ll=long long;

int main(){
    int n,sum=0;
    cin>>n;
    vector<int> dat(n+5);
    rep(i,n){
        cin>>dat[i];
        sum+=abs(dat[i]-dat[i-1]);
    }
    sum+=abs(dat[n]);
    rep(i,n){
        int now=sum;
        now-=abs(dat[i-1]-dat[i]);
        now-=abs(dat[i]-dat[i+1]);
        now+=abs(dat[i-1]-dat[i+1]);
        cout<<now<<endl;
    }
    return 0;
}