#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<int>a(3);
    cin>>a[0]>>a[1]>>a[2];
    int k;
    cin>>k;
    sort(a.begin(),a.end());
    rep(i,k)a[2]*=2;
    cout<<a[0]+a[1]+a[2]<<endl;

}