#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)
        cin>>a[i];
    vector<int> dat=a;
    sort(dat.begin(),dat.end());
    int m=(n+1)/2-1;
    rep(i,n){
        if(a[i]<=dat[m]){
            cout<<dat[m+1]<<endl;
        }
        else{
            cout<<dat[m]<<endl;
        }
    }
    return 0;
}