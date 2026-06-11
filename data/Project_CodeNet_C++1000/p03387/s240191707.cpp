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
    int a,b,c;cin>>a>>b>>c;
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    int atmp=(c-a)/2;
    int btmp=(c-b)/2;
    int ans;
    if((c-a)%2!=(c-b)%2)ans=2;
    else {
        if((c-a)%2==0 && (c-b)%2==0)ans=0;
        else ans=1;
    }
    cout<<ans+atmp+btmp<<endl;
}
