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
    int n,a,b,x,e=0,m=0,h=0;cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x<=a)e++;
        else if(x<=b)m++;
        else h++;
    }
    int ans;
    ans=min(e,m);
    ans=min(ans,h);
    cout<<ans<<endl;
}
