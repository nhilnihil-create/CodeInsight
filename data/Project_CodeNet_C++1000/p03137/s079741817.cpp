#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int t;
    
    t=1;
    while(t--){
        int n,k;
        cin>>k>>n;
        vector<ll> vec, diff;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        if(vec.size()==1){
            cout<<0;
            return 0;
        }
        sort(vec.begin(), vec.end());
        ll ans=0;
        priority_queue<ll> pq;
        for(int i=1;i<n;i++){
            ans=ans+vec[i]-vec[i-1];
            pq.push(vec[i]-vec[i-1]);
        }
        while(k-->1&&!pq.empty()){
            ans=ans-pq.top();
            pq.pop();
        }
        cout<<ans;
    }
}