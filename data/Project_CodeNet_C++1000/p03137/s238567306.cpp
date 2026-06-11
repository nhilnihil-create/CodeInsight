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
    int N,M;cin>>N>>M;
    vector<int>x(M);
    priority_queue<int>pq;
    rep(i,M){
        cin>>x.at(i);
    }
    sort(x.begin(),x.end());
    rep(i,M){
        if(i!=0){
            pq.push(x.at(i)-x.at(i-1));
        }
    }
    if(N>=M){
        cout<<0<<endl;
        return 0;
    }
    int sum=0;
    rep(i,N-1){
        sum+=pq.top();
        pq.pop();
        
    }
    cout<<x.at(M-1)-x.at(0)-sum<<endl;

}