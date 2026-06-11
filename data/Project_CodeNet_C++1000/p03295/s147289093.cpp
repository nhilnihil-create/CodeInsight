#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> wars;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        wars.push_back(make_pair(b,a));
    }
    sort(wars.begin(),wars.end());

    int max_x=-1;
    int broken_bridge=0;
    for(auto war:wars){
        if(war.second>max_x){
            max_x=war.first-1;
            broken_bridge++;
        }        
    }

    cout<<broken_bridge<<endl;
}