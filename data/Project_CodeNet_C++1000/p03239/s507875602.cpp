#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++)
    {
        int f,s;
        cin>>f>>s;
        vp.push_back({f,s});
    }
    int cost=-1;
    for(int i=0;i<vp.size();i++)
    {
        if(t>=vp[i].second){
            if(cost==-1||cost>vp[i].first){
                cost=vp[i].first;
            }
        }
    }
    if(cost==-1)cout<<"TLE";
    else
    cout<<cost;
}