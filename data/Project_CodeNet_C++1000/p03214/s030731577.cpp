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
    int n,a,ans,tmp=0,best=100000000;cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>a;a*=n;
        tmp+=a;vec[i]=a;
    }
    tmp/=n;
    for(int i=0;i<n;i++){
        if(abs(tmp-vec[i])<best){
            best=abs(tmp-vec[i]);
            ans=i;
        }
    }
    cout<<ans<<endl;
}
