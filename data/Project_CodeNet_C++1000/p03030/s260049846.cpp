#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<pair<string,int>,int> &a, const pair<pair<string,int>,int> &b){
    if(a.first.first != b.first.first){
        return a.first.first<b.first.first;
    }
    return a.first.second > b.first.second;
}

int main(){
    int n;
    cin>>n;
    vector<pair<pair<string,int>,int>> t(n);
    for(int i = 0;i<n;++i){
        cin>>t[i].first.first>>t[i].first.second;
        t[i].second = i+1;
    }
    sort(t.begin(),t.end(),cmp);
    for(int i = 0;i<n;++i){
        cout<<t[i].second<<endl;
    }
    return 0;
}