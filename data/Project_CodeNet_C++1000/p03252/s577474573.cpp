#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    string s,t;
    cin>>s>>t;
    map<char,int> mci1,mci2;
    rep(i,s.size()){
        mci1[s[i]]++;
        mci2[t[i]]++;
    }
    if(mci1.size()!=mci2.size()){
        cout<<"No"<<endl;
        return 0;
    }
    vector<int> v1(s.size(),0),v2(t.size(),0);
    rep(i,s.size()){
        v1[i]=mci1[s[i]];
        v2[i]=mci2[t[i]];
    }
    rep(i,s.size()){
        if(v1[i]!=v2[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}