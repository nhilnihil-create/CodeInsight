#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll BIG=1e9;

ll d[100001];


int main(){
    int K;cin>>K;
    queue<int> Q;
    d[1]=1;
    Q.push(1);
    
    while(!Q.empty()){
        int x=Q.front();
        //cout<<d[x]<<':'<<x<<endl;
        int p=(10*x)%K, q=(x+1)%K;
        while(d[p]==0 || d[p]>d[x]){
            d[p]=d[x];
            Q.push(p);
            p=(10*p)%K;
        }
        
        if(d[q]==0 || d[q]>d[x]+1){
            d[q]=d[x]+1;
            Q.push(q);
        }
        Q.pop();

    }
    //for(int i=0;i<K;i++) if(d[i]==0) cout<<"0:"<<i<<endl;
    cout<<d[0]<<endl;


}