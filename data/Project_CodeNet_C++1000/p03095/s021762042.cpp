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
    string s;cin>>s;
    map<char,int> dic;
    for(char c:s){
        dic[c]++;
    }
    lint ans=1,mod=1000000007;
    for(auto p:dic){
        ans*=(p.second+1);
        ans%=mod;
    }
    if(ans==0)ans=mod-1;
    else ans--;
    cout<<ans<<endl;
}
