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
    int n,nc,sum=0;cin>>n;
    nc=n;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    if(nc%sum==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
