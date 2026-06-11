#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d[100000];
deque<ll>que;
int main(void){
    cin>>n;
    d[1]=1;
    que.push_back(1);
    while(que.size()){
        ll p=que.front();
        que.pop_front();
        for(int i=0;i<2;i++){
            ll u=i?(p+1)%n:(p*10)%n;
            if(d[u]&&d[u]<=d[p]+i)continue;
            d[u]=d[p]+i;
            i?que.push_back(u):que.push_front(u);
        }
    }
    cout<<d[0]<<endl;
}
