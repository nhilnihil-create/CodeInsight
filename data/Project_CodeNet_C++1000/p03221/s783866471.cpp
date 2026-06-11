#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int p,y;
    map<pair<int,int>,int> mp;
    pair<int,int> ans[m];
    vector<int> v[n+1];
    for(int i=0;i<m;i++){
        cin >> p >> y;
        mp[make_pair(p,y)]=i;
        v[p].push_back(y);
    }
    int it;
    for(int i=1;i<n+1;i++){
        it=1;
        sort(v[i].begin(),v[i].end());
        for(int u:v[i]){
            ans[mp[make_pair(i,u)]]=make_pair(i,it);
            it++;
        }
    }
    string S;
    for(int i=0;i<m;i++){
        it=10;
        for(int j=0;j<6;j++){
            S[5-j]=(ans[i].first%it)+'0';
            ans[i].first/=10;
        }
        for(int j=0;j<6;j++){
            S[11-j]=(ans[i].second%it)+'0';
            ans[i].second/=10;
        }
        for(int j=0;j<12;j++)cout << S[j];
        cout << endl;
    }
}