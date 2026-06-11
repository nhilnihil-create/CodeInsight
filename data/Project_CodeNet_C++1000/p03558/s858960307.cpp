#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    deque<int>q;
    q.push_front(1);
    int check[n]={};
    vector<int>cost(n,100);
    cost[1]=1;
    while(*q.begin()!=0){
        int x=*q.begin();
        q.pop_front();
        check[x]=1;
        //cout<<x<<" "<<cost[x]<<endl;
        if(check[x*10%n]==0){
            q.push_front(x*10%n);
            cost[x*10%n]=min(cost[x*10%n],cost[x]);
        }
        if(check[(x+1)%n]==0){
            q.push_back((x+1)%n);
            cost[(x+1)%n]=min(cost[(x+1)%n],cost[x]+1);
        }
    }
    cout<<cost[0]<<endl;
    return 0;
}