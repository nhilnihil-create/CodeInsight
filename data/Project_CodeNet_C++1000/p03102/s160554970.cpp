#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<vector<int>>sorce(n,vector<int>(m));
    vector<int>b(m);
    vector<int>seki(n,0);
    rep(i,m) cin>>b.at(i);
    rep(i,n) rep(j,m){
        cin>>sorce[i][j];
    }
    int cnt=0;
    rep(i,n){
        rep(j,m){
            seki.at(i)+=sorce[i][j]*b[j];
            
        }
        if(seki.at(i)+c>0) cnt+=1;
    }
    cout<<cnt<<endl;

}