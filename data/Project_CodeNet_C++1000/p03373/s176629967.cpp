#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    lint ans=10000000000;
    for(int i=0;i<=2*max(x,y);i+=2){
        lint tmp=0;
        tmp+=c*i;
        tmp+=a*max(x-i/2,0);
        tmp+=b*max(y-i/2,0);
        if(tmp<ans)ans=tmp;
    }
    cout<<ans<<endl;
}
