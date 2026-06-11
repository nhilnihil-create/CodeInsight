#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll mod =1000000007;
int main(){
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<long long> a(x), b(x), c(x);
    for(int i=0; i<x; i++) cin>>a[i];
    for(int i=0; i<y; i++) cin>>b[i];
    for(int i=0; i<z; i++) cin>>c[i];
    priority_queue<long long> pq;
    for(int j=0; j<x; j++){
        for(int l =0; l<y; l++){
            pq.push(a[j] +b[l]); 
        }
    }
    priority_queue<long long> ans;
    for(int i=0; i<z; i++){
        priority_queue<long long> tpq=pq;
        for(int j=0; j<min(k,x*y); j++){
            long long tmp = tpq.top();
            tpq.pop();
            ans.push(tmp +c[i]);
        }
    }
    for(int i=0; i<k; i++){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}