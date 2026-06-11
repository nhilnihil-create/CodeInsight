#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int cnt=0; 

void f(vector<int>& a){
    if(a[0]==a[1] && a[1]==a[2]) cout<<cnt<<"\n";
    else{
        sort(a.begin(),a.end());
        if(a[1]-a[0]>=2){
            a[0]+=2;
        }
        else{
            a[0]++;
            a[1]++;
        }
        cnt++;
        f(a);
    }
}

int main(){
    vector<int> a(3);
    rep(i,3) cin>>a[i];
    f(a);
    //cout<<cnt<<"\n";

    return 0;
}