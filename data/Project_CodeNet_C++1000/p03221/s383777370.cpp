#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using itn = int;

int main(void){
    int n,m;
    cin >> n >> m;
    int p[m],y[m];
    vector<pair<int,int>> v;
    for(int i = 0;i < m;i++){
        cin >> p[i] >> y[i];
        v.push_back(pair<int,int>(y[i],p[i]));
    }
    sort(v.begin(),v.end());
    
    int num[n+1];
    for(int i = 1;i <= n;i++)num[i] = 1;
    
    map<pair<int,int>,string> mp;
    for(int i = 0;i < m;i++){
        int a = 6 - to_string(v[i].second).size();
        string s;
        for(int i = 0;i < a;i++)s += "0";
        s += to_string(v[i].second);
        
        int b = 6 - to_string(num[v[i].second]).size();
        for(int i = 0;i < b;i++)s += "0";
        s += to_string(num[v[i].second]);
        num[v[i].second]++;
        
        mp[pair<int,int>(v[i].second,v[i].first)] = s;
    }
    
    for(int i = 0;i < m;i++)cout << mp[pair<int,int>(p[i],y[i])] << endl;
}