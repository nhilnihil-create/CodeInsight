#include <bits/stdc++.h>
#define int long long
using namespace std;
int N;
int m[55];
vector<pair<int,int>> v;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)cin>>m[i];
    auto p=max_element(m,m+N);
    auto q=min_element(m,m+N);
    if(*p+*q>0){
        if(m[0]>0){
            v.push_back({p-m,0});
            m[0]+=*p;
        }
        v.push_back({p-m,0});
        m[0]+=*p;
        for(int i=1;i<N;i++){
            if(m[i]>=m[i-1])continue;
            if(m[i]<0){
                v.push_back({i-1,i});
                m[i]+=m[i-1];
            }
            v.push_back({i-1,i});
            m[i]+=m[i-1];
        }
    }
    else {
        if(m[N-1]>0){
            v.push_back({q-m,N-1});
            m[N-1]+=*q;
        }
        v.push_back({q-m,N-1});
        m[N-1]+=*q;
        for(int i=N-2;i>=0;i--){
            if(m[i]<=m[i+1])continue;
            if(m[i]>0){
                v.push_back({i+1,i});
                m[i]+=m[i+1];
            }
            v.push_back({i+1,i});
            m[i]+=m[i+1];
        }
    }
    cout<<v.size()<<'\n';
    for(auto p:v)cout<<p.first+1<<' '<<p.second+1<<'\n';
    return 0;
}