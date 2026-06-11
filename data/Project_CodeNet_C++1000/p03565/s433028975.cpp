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
    string s,t; cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<string> q;
    rep(i,n-m+1){
        rep(j,m){
            if(s[i+j]!='?' && s[i+j]!=t[j])
            break;
            if(j==m-1){
                string S=s;
                rep(k,m) S[i+k]=t[k];
                rep(k,n)if(S[k]=='?') S[k]='a';
                q.push_back(S);
            }
        }
    }
    if(q.size()==0) cout<<"UNRESTORABLE"<<endl;
    else{
        sort(al(q));
        cout<<q[0]<<endl;
    }
}
