#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<ll> d(n);
    vector<int> w(n,1);
    map<ll,int> mp;
    for(int i=0;i<n;i++){
        cin>>d[i];
        mp[d[i]]=i;
    }
    vector<pair<int,int> > res;
    for(int tm=1;tm<n;tm++){
        map<ll,int>::reverse_iterator it=mp.rbegin();
        int i=it->second;
        ll wt=d[i]-n+w[i]+w[i];
        if(mp.find(wt)==mp.end()||mp[wt]==i){
            cout<<-1<<endl;
            return 0;
        }
        int j=mp[wt];
        res.emplace_back(i,j);
        w[j]+=w[i];
        mp.erase(--mp.end());
    }
    vector<ll> rd(n,-1);
    rd[0]=0;
    vector<vector<int> > g(n);
    for(pair<int,int> p : res){
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }
    vector<int> q(1,0);
    for(int b=0;b<q.size();b++){
        for(int j:g[q[b]]){
            if(rd[j]==-1){
                q.push_back(j);
                rd[j]=rd[q[b]]+1;
            }
        }
    }
    if(accumulate(rd.begin(),rd.end(),0ll)!=d[0]){
        cout<<-1<<endl;
        return 0;
    }
    for(pair<int,int> p : res){
        cout<<p.first+1<<' '<<p.second+1<<endl;
    }

    return 0;
}