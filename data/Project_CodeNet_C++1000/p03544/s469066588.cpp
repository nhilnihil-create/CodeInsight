#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define str to_string
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
    int n;cin>>n;
    vector<lint> lucas(n+1);
    lucas[0]=2;
    lucas[1]=1;
    for(int i=2;i<n+1;i++){
        lucas[i]=lucas[i-1]+lucas[i-2];
    }
    cout<<lucas[n]<<endl;
}