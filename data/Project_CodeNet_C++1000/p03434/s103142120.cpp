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
    priority_queue<int>pq;
    int tmp;
    rep(i,N){
        cin>>tmp;
        pq.push(tmp);
    }
    int sumA=0;
    int sumB=0;
    int judge=0;
    while(!pq.empty()){
        if(judge==0){
            sumA+=pq.top();
            pq.pop();
            judge=1;
        }else if(judge==1){
            sumB+=pq.top();
            pq.pop();
            judge=0;
        }
    }
    cout<<sumA-sumB<<endl;
}