#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    vector<vector<int>> c(100000,vector<int>());
    for(int i=0;i<m;i++){
        int p,y;
        cin>>p>>y;
        p--;
        v[i]=make_pair(p,y);
        c[p].push_back(y);
    }
    for(int i=0;i<n;i++) sort(c[i].begin(),c[i].end());
    for(int i=0;i<m;i++){
        int p=v[i].first;
        int y=find(c[p].begin(),c[p].end(),v[i].second)-c[p].begin();
        p++;
        y++;
        printf("%06d%06d\n",p,y);
    }
}