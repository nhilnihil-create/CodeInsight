#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n);
    vector<int> p(m),y(m);
    for(int i=0;i<m;i++){
        cin>>p[i]>>y[i];
        v[p[i]-1].emplace_back(make_pair(y[i],i));
    }
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++){
            y[v[i][j].second]=j+1;
        }
    }
    for(int i=0;i<m;i++){
        printf("%06d%06d\n",p[i],y[i]);
    }
}