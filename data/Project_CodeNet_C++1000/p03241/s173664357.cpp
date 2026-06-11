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
    int n,m;cin>>n>>m;
    int a=sqrt(m);
    vector<int> divisor(0);
    for(int i=a;i>=1;i--){
        if(m%i==0){divisor.pb(i);divisor.pb(m/i);}
    }
    sort(all(divisor));
    for(int x:divisor){
        if(x>=n){
            cout<<m/x<<endl;
            break;
        }
    }
}
