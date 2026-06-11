#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX
typedef pair<long long, long long> P;
int main(){
    string s,t;
    cin>>s>>t;
    
    long long ans=0;
    vector<char>d(30);
    rep(i,30){
        d[i]='0';
    }
    rep(i,s.size()){
        int sz= (int) s[i]-'a';
        if(d[sz]=='0' ||d[sz]==t[i]){
            d[sz]=t[i];
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    rep(i,30){
        d[i]='0';
    }
    rep(i,s.size()){
        int sz= (int) t[i]-'a';
        if(d[sz]=='0' ||d[sz]==s[i]){
            d[sz]=s[i];
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
