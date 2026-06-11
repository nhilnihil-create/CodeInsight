#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,r;
    cin>>N;
    string S="";
    while(N!=0){
        r=N%2;
        if(r<0) r+=2;
        N=(N-r)/(-2);
        S+=(char)('0'+r);
    }
    reverse(S.begin(),S.end());
    if(S=="") cout<<"0"<<endl;
    else cout<<S<<endl;
}