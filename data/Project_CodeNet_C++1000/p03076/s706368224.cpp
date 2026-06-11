#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
    vector<int>demand(5);
    rep(i,5)cin>>demand[i];
    rep(i,4){
        if(demand[i]%10){
            if(demand[i+1]%10==0)swap(demand[i],demand[i+1]);
            else if(demand[i+1]%10>demand[i]%10)swap(demand[i],demand[i+1]);
        }
    }
    rep(i,4){
        if(demand[i]%10)demand[i]+=10-demand[i]%10;
    }
    int ans=0;
    rep(i,5)ans+=demand[i];
    cout<<ans<<endl;
    return 0;
}