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
    int n,k,ans=0;cin>>n>>k;
    string s;cin>>s;
    vector<int> vec(0);
    int tmp=1,cnt=0;
    for(int i=0;i<n;i++){
        if((char)('0'+tmp)!=s[i]){
            vec.pb(cnt);
            cnt=1;
            tmp=1-tmp;
        }
        else cnt++;
    }
    if(cnt>0)vec.pb(cnt);
    if(s[n-1]=='0')vec.pb(0);
    int sz=vec.size();
    if(sz/2<=k)ans=n;
    else{
        tmp=0;
        for(int i=0;i<2*k+1;i++){
            tmp+=vec[i];
        }
        ans=max(ans,tmp);
        for(int i=2*k+1;i<sz;i+=2){
            tmp-=(vec[i-2*k-1]+vec[i-2*k]);
            tmp+=(vec[i]+vec[i+1]);
            ans=max(ans,tmp);
        }
    }
    cout<<ans<<endl;
}
