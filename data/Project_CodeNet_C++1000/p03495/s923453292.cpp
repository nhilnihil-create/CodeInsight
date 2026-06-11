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
    int n,k,a;cin>>n>>k;
    map<int,int> dic;
    for(int i=0;i<n;i++){
        cin>>a;dic[a]++;
    }
    vector<int> vec(0);
    for(auto p:dic){
        vec.pb(p.second);
    }
    sort(all(vec),greater<int>());
    int ans=0;
    for(int i=k;i<vec.size();i++){
        ans+=vec[i];
    }
    cout<<ans<<endl;
}
