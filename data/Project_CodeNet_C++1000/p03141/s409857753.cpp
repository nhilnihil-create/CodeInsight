//#define _GLIBCXX_DEBUG
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
    vector<vector<lint>> vec(n,vector<lint> (3,0));
    for(int i=0;i<n;i++){
        cin>>vec[i][1]>>vec[i][2];
        vec[i][0]=vec[i][1]+vec[i][2];
    }
    sort(all(vec),greater<vector<lint>>());
    lint ans=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            ans+=vec[i][1];
        }
        else {
            ans-=vec[i][2];
        }
    }
    cout<<ans<<endl;
}
