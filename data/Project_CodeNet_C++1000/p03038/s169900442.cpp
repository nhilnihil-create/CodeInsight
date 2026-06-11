#include<iostream>
#include<algorithm>
#include<numeric>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<pair<ll,int>> q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(make_pair(a,1));
    }
    for(int i=0;i<m;i++){
        int b,c;
        cin>>b>>c;
        q.push(make_pair(c,b));
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        auto p=q.top();
        q.pop();
        ans+=p.first;
        if(p.second>1){
            p.second--;
            q.push(p);
        }
    }
    cout<<ans<<endl;
} 