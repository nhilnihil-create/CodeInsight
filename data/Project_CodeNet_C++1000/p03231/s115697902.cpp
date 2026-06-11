#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    lint n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    lint lcm=n/__gcd(n,m)*m;
    lint nc=lcm/n,mc=lcm/m;
    vector<pair<lint,char>> vec(0);
    int np=1,mp=1;
    for(int i=0;i<n;i++){
        vec.pb(make_pair(np,s[i]));
        np+=nc;
    }
    for(int i=0;i<m;i++){
        vec.pb(make_pair(mp,t[i]));
        mp+=mc;
    }
    sort(all(vec));
    lint rn=0;char rc;
    for(auto p:vec){
        if(p.first==rn){
            if(rc!=p.second)lcm=-1;
        }
        rn=p.first;
        rc=p.second;
    }
    cout<<lcm<<endl;
}
