#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>food(m,0);
    rep(i,n){
        int k;
        cin>>k;
        rep(j,k){
            int a;
            cin>>a;
            food.at(a-1)+=1;
        }
    }
    int cnt=0;
    rep(i,m){
        if(food[i]==n){
            cnt+=1;
        }
    }
    cout<<cnt<<endl;

}