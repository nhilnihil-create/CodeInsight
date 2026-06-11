#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>x(m);
    rep(i,0,m){
        cin>>x.at(i);
    }
    sort(all(x));
    vector<int>sa(m-1);

    if(n>=m){
        cout<<0<<endl;
        return 0;
    }
    rep(i,0,m-1){
        sa.at(i)=abs(x.at(i+1)-x.at(i));
    }
    sort(all(sa),greater<int>());
    int sum=0;
    
    rep(i,0,n-1){
        sum+=sa.at(i);
        //cout<<sa.at(i)<<endl;
    }
    cout<<abs(x.at(m-1)-x.at(0))-sum<<endl;
return 0;
}
