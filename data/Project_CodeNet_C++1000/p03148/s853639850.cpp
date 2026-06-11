#include <bits/stdc++.h>
#define rp(i,n) for(ll i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
using G=vector<vector<int>>;

int main(){
    ll n,k;
    cin >> n >> k;
    priority_queue<P> allque;
    vector<priority_queue<ll>> eachque(n);
    vector<ll> group(n,0);
    priority_queue<P,vector<P>,greater<P>> fireque;
    rp(i,n){
        ll t,d;
        cin >> t >> d;
        t--;
        allque.push(make_pair(d,t));
        eachque[t].push(d);
        group[t]++;
    }
    ll dsum=0ll;
    ll kindnum=0ll;
    vector<int> used(n,0);
    vector<ll> topofloser;
    rp(i,k){
        P p=allque.top(); allque.pop();
        fireque.push(p);
        dsum += p.first;
        if(used[p.second]==0) kindnum++;
        used[p.second]++;
    }
    ll ans=dsum+kindnum*kindnum;
   rp(i,n){
        if(group[i]>0&&used[i]==0) topofloser.push_back(eachque[i].top());
    }
    sort(topofloser.begin(),topofloser.end());
    reverse(topofloser.begin(),topofloser.end());
    ll restkind=topofloser.size();
    /*vector<ll> sumtol(restkind+1,0);
    rp(i,restkind) sumtol[i+1]=sumtol[i]+topofloser[i];*/
   ll firing=0ll;
    for(ll i=0;i<restkind;){
        if(fireque.empty()) break;
        P p=fireque.top(); fireque.pop();
        if(used[p.second]==1)continue;
        firing=p.first;
        dsum=dsum-firing+topofloser[i];
        ans=max(ans,dsum+(kindnum+i+1ll)*(kindnum+i+1ll));
        i++;
    }
    cout << ans << endl;
    return 0;
}