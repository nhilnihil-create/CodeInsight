#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)
#define p(a,b) printf(a,b);
#define c(s) cout<< (s) << endl;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define cyn(c) cout<<(c?"Yes":"No")<<endl;
#define cYN(c) cout<<(c?"YES":"NO")<<endl;
#define pyn(o,c) printf(o,c?"Yes":"No");
#define pYN(o,c) printf(o,c?"YES":"NO");
typedef long long LL;
template <class T>
bool contain(const std::string &s, const T &v)
{
    return s.find(v) != std::string::npos;
}

int main()
{
    string s; cin>>s;
    if(s.size()==2){
        c(s);
    }else{
        reverse(s.begin(),s.end());
        c(s);
    }
}
