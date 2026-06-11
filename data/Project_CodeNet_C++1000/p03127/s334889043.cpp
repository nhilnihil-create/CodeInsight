#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    int ans;
    priority_queue<int>pq;
    rep(i,N){
        int a;
        cin>>a;
        pq.push(a);
    }
    while(1){
        int num1,num2;        
        if(pq.size()==1){
            ans=pq.top();
            pq.pop();
            cout<<ans<<endl;
            break;
        }else{
            num1=pq.top();
            pq.pop();
            num2=pq.top();
            pq.pop();
        }
        while(num1>=num2){
            num1-=num2;
        }
        if(num1>0){
            pq.push(num1);
        }
        pq.push(num2);
    }
}