//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

vector<in> yakusu(in n){//約数の全列挙
    vector<in> ret(0);
    for(in i=1;i*i<=n;i ++){
        if(n%i==0){
            ret.emplace_back(i);
            if(i*i<n) ret.emplace_back(n/i);
        }
    }
    return ret;
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n;
    cin>>n;
    auto a=yakusu(n);
    in ans=0ll;
    for(auto x:a){
        in y=n/x-1ll;
        if(x<y) ans +=y;
    }
    cout<<ans<<endl;
}