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
    int n,x,a;cin>>n>>x;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>a;vec[i]=a;
    }
    sort(all(vec));
    int ans=0;
    for(int i=0;i<n;i++){
        if(x<vec[i]){
            x=0;break;
        }
        else if(x>=vec[i]){
            ans++;
            x-=vec[i];
        }
    }
    if(x>0)ans--;
    cout<<ans<<endl;
}
