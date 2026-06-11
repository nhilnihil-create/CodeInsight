#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum-n<<"\n";
    return 0;
}