#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    vector<int>sei;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            sei.push_back(i);
        }
    }
    sort(sei.begin(),sei.end());
    reverse(sei.begin(),sei.end());
    cout<<sei.at(k-1)<<endl;
}