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
    int a,b,k;cin>>a>>b>>k;
    for(int i=0;i<k;i++){
        if(i%2==0){
            if(a%2==1)a--;
            a/=2;
            b+=a;
        }
        else{
            if(b%2==1)b--;
            b/=2;
            a+=b;
        }
    }
    cout<<a<<" "<<b<<endl;
}
