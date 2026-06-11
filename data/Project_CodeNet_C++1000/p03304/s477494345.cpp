#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=998244353;

int main(){
    double n;
    cin >> n;
    double m;
    cin >> m;
    double d;
    cin >> d;

    double k=(2*(n-d))/(n*n);
    if(d==0){k/=2;}


    cout << fixed << setprecision(15);
    cout<<(m-1)*k<<endl;


    return 0;
}
