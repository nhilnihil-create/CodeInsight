#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    priority_queue<int> pq;
    map<int,int> mp;
    pair<ll,int>p[100010];

    int N,K;cin>>N>>K;
    int t;ll d;
    for(int i=0;i<N;i++){
        cin>>t>>d;
        p[i]={-d,t};
    }
    sort(p,p+N);
    ll sum=0,kind=0;
    for(int i=0;i<K;i++){
        sum-=p[i].first;
        mp[p[i].second]++;
        if(mp[p[i].second]==1)kind++;
        if(mp[p[i].second]>=2)pq.push(i);
    }
    
    sum+=(ll)pow(kind,2);
    
    ll ans=sum;
    int i=K;
    while(!pq.empty() && i<N){
        if(mp[p[i].second]==0){
            int m=pq.top();
            ll k=kind;
            kind++;
            sum+=(ll)pow(kind,2)-(ll)pow(k,2)+p[m].first-p[i].first;
            ans=max(ans,sum);
            mp[p[i].second]++;
            pq.pop();
        }
        i++;
    }
    cout<<ans<<endl;
    return 0;
}