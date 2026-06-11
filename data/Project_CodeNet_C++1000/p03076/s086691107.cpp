#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long int;

int main(){
    vector<int>dishes(5);
    rep(i,5) cin>>dishes.at(i);
    vector<int>notpit;
    rep(i,5){
        if(dishes.at(i)%10!=0){
            notpit.push_back(10-(dishes.at(i)%10));
        }
    }
    sort(notpit.begin(),notpit.end());
    int time=0;
    sort(dishes.begin(),dishes.end());
    rep(i,5) time+=dishes.at(i);
    if(notpit.size()>0) rep(i,notpit.size()-1) time+=notpit.at(i);
    cout<<time<<endl;
}