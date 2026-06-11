#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<long long int>x(n);
    vector<long long int>copy(n);
    rep(i,n)cin>>x[i];
    rep(i,n)copy[i]=x[i];
    sort(copy.begin(),copy.end());
    int indeb=n/2-1;
    int indea=n/2;
    rep(i,n){
        if(x[i]>=copy[indea])cout<<copy[indeb]<<endl;
        else cout<<copy[indea]<<endl;
       

    }
}