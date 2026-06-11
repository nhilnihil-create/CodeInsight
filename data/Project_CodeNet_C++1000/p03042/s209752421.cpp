#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353,INF=1e18;



int main() {
    int S;
    cin>>S;
    int a=S/100,b=S%100;
    if(0<a && a<13 && 0<b && b<13){
        cout<<"AMBIGUOUS"<<endl;return 0;
    }
    if(0<a && a<13){
        cout<<"MMYY"<<endl;return 0;
    }
    if(0<b && b<13){
        cout<<"YYMM"<<endl;return 0;
    }
    cout<<"NA"<<endl;
}