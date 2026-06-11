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
    string a,b,c;cin>>a>>b>>c;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]&&b[i]!=c[i]&&a[i]!=c[i]){
            ans+=2;
        }
        else if(a[i]==b[i]&&b[i]==c[i]){
            continue;
        }
        else ans+=1;
    }
    cout<<ans<<endl;
}
