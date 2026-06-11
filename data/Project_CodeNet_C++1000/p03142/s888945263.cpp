#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b,ch[100000],nod[100000];
vector<ll>v1[100000];
queue<ll>que;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n+m-1;i++){
        cin>>a>>b;
        a--,b--;
        v1[a].push_back(b);
        nod[b]++;
        ch[b]=1;
    }
    for(int i=0;i<n;i++){
        if(ch[i]==0){
            que.push(i);
        }
    }
    while(que.size()){
        ll q=que.front();
        que.pop();
        for(auto x:v1[q]){
            if(nod[x]==1){
                que.push(x);
                ch[x]=q+1;
            }
            nod[x]--;
        }
    }
    for(int i=0;i<n;i++)cout<<ch[i]<<endl;
}
