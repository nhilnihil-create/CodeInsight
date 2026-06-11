//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s,t,ans="Yes"; cin>>s>>t;
    map<char,char> q;
    set<char> r;
    rep(i,s.size()){
        if(q.count(s[i])){
            if(q[s[i]]!=t[i]){
                ans="No";
                break;
            }
        }
        else{
            if(r.count(t[i])){
                ans="No";
                break;
            }
            else{
                r.insert(t[i]);
                q[s[i]]=t[i];
            }
        }
    }
    cout<<ans<<endl;
}