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
    int ma=0,mi=1000000001,n,a;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>ma)ma=a;
        if(a<mi)mi=a;
    }
    cout<<ma-mi<<endl;
}
