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
    int x,a=0,b=0,n;cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>x;vec[i]=x;
    }
    sort(all(vec));
    reverse(all(vec));
    for(int i=0;i<n;i++){
        if(i%2==0)a+=vec[i];
        else b+=vec[i];
    }
    cout<<a-b<<endl;
}
