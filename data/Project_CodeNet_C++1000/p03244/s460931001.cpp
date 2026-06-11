#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    map<int,int> mp1,mp2;
    rep(i,n/2){
        int x,y;cin>>x>>y;
        mp1[x]++;
        mp2[y]++;
    }
    priority_queue<pair<int,int>> que1,que2;
    for(auto& p:mp1){
        que1.push({p.second,p.first});
    }
    for(auto& p:mp2){
        que2.push({p.second,p.first});
    }
    int x1=que1.top().first,y1=que1.top().second;que1.pop();
    int x2=(que1.size())? que1.top().first:0;que1.pop();
    int x3=que2.top().first,y3=que2.top().second;que2.pop();
    int x4=(que2.size())? que2.top().first:0;que2.pop();
    if(y1!=y3){
        ll res=n-(x1+x3);
        cout<<res<<endl;
        return 0;
    }else{
        ll buf1=n-(x1+x4),buf2=n-(x2+x3);
        ll res=min(buf1,buf2);
        cout<<res<<endl;
        return 0;
    }
}