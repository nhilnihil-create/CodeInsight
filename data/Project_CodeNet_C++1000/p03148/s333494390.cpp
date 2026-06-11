#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
    #define int long long
    int n,k;
    cin>>n>>k;
    int t[n],d[n],used[n]={};
    priority_queue<pair<int,int>>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    for(int i=0;i<n;i++){
        cin>>t[i]>>d[i];
        q1.push({d[i],t[i]-1});
    }
    long long neta=0,value=0;
    for(int i=0;i<k;i++){
        P p=q1.top();
        q1.pop();
        value+=p.first;
        if(used[p.second])q2.push(p.first);
        else{
            neta++;
            used[p.second]=1;
        }
    }
    long long m=neta*neta+value;
    while(q1.size() && q2.size()){
        P p=q1.top();
        q1.pop();
        if(used[p.second]==0){
            neta++;
            used[p.second]=1;
            value+=p.first-q2.top();
            q2.pop();
            m=max(m,neta*neta+value);
        }
    }
    cout<<m<<endl;
    return 0;
}