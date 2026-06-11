#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    ll N;
    cin >> N;
    ll A;
    cin >> A;
    ll B;
    cin >> B;
    cout<<min(A,B)<<" "<<max(0LL,A+B-N)<<endl;
    
    return 0;
}
