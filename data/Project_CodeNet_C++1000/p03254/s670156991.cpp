#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    int cnt=0;
    
    if(sum==x) cout<<n<<"\n";
    else if(sum<x){
        rep(i,n){
            if(a[i]>x) break;
            else{
                cnt++;
                x-=a[i];
            }
        }
        cout<<cnt-1<<"\n";
    }
    else{
        rep(i,n){
            if(a[i]>x) break;
            else{
                cnt++;
                x-=a[i];
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}