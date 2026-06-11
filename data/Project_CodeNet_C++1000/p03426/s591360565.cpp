#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    int h, w, d;
    cin>>h>>w>>d;
    vector<pair<int, int> > v(h*w+1);
    rep(i, h)rep(j, w){
        int a;
        cin>>a;
        v[a]=make_pair(i, j);
    }
    int q;
    cin>>q;
    vector<int> dist(h*w+1);
    for(int i=d+1;i<=h*w;i++){
        dist[i]=dist[i-d]+abs(v[i].first-v[i-d].first)+abs(v[i].second-v[i-d].second);
    }
    vector<pair<int, int> > Q(q);
    rep(i, q){
        int l, r;
        cin>>l>>r;
        Q[i]=make_pair(l, r);
    }
    rep(i, q){
        int ans=dist[Q[i].second]-dist[Q[i].first];
        cout<<ans<<endl;
    }
    return 0;
}