#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n,m,ch[100000],s,t;
vector<ll> v[100000];
queue<ll> que;
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ch[0]=1;
    que.push(0);
    while(que.size()){
        ll q=que.front();
        que.pop();
        for(ll x:v[q]){
            if(ch[x]!=0){
                if(ch[q]==ch[x]){cout<<n*(n-1)/2-m<<endl;return 0;}
                continue;
            }
            que.push(x);
            if(ch[q]==1)ch[x]=2;
            else ch[x]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(ch[i]==1)s++;
        else t++;
    }
    cout<<s*t-m<<endl;
}
