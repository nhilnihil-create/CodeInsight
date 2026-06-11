#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod=1000000007;

int main(){
    string s;cin>>s;
    int ssz=s.size();
    int a[3]={};
    rep(i,ssz){
        if(s[i]=='a')a[0]++;
        else if(s[i]=='b')a[1]++;
        else a[2]++;
    }
    sort(a,a+3);
    if(a[2]-a[0]>1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
