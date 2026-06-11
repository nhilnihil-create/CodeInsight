#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    string t="keyence";
    rep(i,7){
        string x=s.substr(0,i)+s.substr(s.size()-7+i,7-i);
        if(x==t){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}