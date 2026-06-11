#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin >> n >> c;
    int ans=1;
    pair<pair<int,int>,int> p[n];
    for(int i=0;i<n;i++)cin >> p[i].first.first >> p[i].first.second >> p[i].second;
    sort(p,p+n);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(p[0].first.second,p[0].second));
    for(int i=1;i<n;i++){
        vector<pair<int,int> > tmp;
        while(q.top().first<p[i].first.first && !q.empty())q.pop();
        while((q.top().first==p[i].first.first && q.top().second<=p[i].second) && !q.empty()){
            if(q.top().second<p[i].second)tmp.push_back(make_pair(q.top().first,q.top().second));
            q.pop();
        }
        for(auto u:tmp)q.push(u);
        q.push(make_pair(p[i].first.second,p[i].second));
        ans=max(ans,(int)q.size());
    }
    cout << ans;
}