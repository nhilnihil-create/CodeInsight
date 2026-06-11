#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<pair<long long,int>> pq;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        pq.push(make_pair(a,1));
    }
    for(int i=0;i<m;++i){
        int b;
        long long c;
        cin>>b>>c;
        pq.push(make_pair(c,b));
    }

    long long ans=0;
    int cur=0;
    while(n>cur){
        pair<long long,int> p=pq.top();
        pq.pop();
        int t=cur+p.second>n?n-cur:p.second;
        cur+=t;
        ans+=p.first*t;
    }

    cout<<ans<<endl;
}