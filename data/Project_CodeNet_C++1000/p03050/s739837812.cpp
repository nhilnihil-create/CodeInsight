#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
    ll N,sum=0;
    cin>>N;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0&&i<N/i-1) sum+=N/i-1;
    }
    cout<<sum<<endl;
}
