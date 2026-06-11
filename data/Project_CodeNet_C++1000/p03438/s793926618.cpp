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
    string ans="Yes";
    int n,x,fusoku;cin>>n;
    lint suma=0,sumb=0;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>x;suma+=x;a[i]=x;
    }
    for(int i=0;i<n;i++){
        cin>>x;sumb+=x;b[i]=x;
    }
    lint allowed=sumb-suma,needed=0;
    if(suma>sumb)ans="No";
    else{
        for(int i=0;i<n;i++){
            fusoku=b[i]-a[i];
            if(fusoku<=0)continue;
            needed+=(fusoku+1)/2;
        }
        if(needed>allowed)ans="No";
    }
    cout<<ans<<endl;
}
