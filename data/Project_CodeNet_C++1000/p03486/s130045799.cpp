#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    bool ok=true;
    for(int i=0;i<s.length()&&i<t.length();i++)
    {
        // cout<<s[i]<<" "<<t[t.length()-i-1]<<endl;
        if(s[i]==t[t.length()-i-1])continue;
        else if(s[i]<t[t.length()-i-1])
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        ok=false;
    }
    if(s.length()<t.length()&&ok)cout << "Yes" <<endl;
    else cout<<"No"<<endl;
    return 0;
}