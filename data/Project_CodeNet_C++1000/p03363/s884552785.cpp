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
    int n;cin>>n;
    vector<lint> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<lint> ruiseki(n+1);
    for(int i=1;i<n+1;i++)ruiseki[i]=a[i-1];
    for(int i=1;i<n+1;i++)ruiseki[i]+=ruiseki[i-1];
    map<lint,int> s;
    for(int i=0;i<n+1;i++)s[ruiseki[i]]++;
    lint ans=0,x;
    for(auto p:s){
        x=p.second;
        ans+=x*(x-1)/2;
    }
    cout<<ans<<endl;
}
