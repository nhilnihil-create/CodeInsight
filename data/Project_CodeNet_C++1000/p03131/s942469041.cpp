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
    lint ans,k,a,b;cin>>k>>a>>b;
    if(b-a>2){
        if(a-1>=k){
            ans=k+1;
        }
        else{
            k-=(a-1);
            ans=a;
            if(k%2==1){ans++;k--;}
            ans+=(b-a)*(k/2);
        }
    }
    else{
        ans=k+1;
    }
    cout<<ans<<endl;
}
