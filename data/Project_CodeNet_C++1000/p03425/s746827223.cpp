#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<string> S(N);
    rep(n,0,N) cin>>S.at(n);

    set<char> initS{'M','A','R','C','H'};
    map<char,int> mapS;
    for(auto s:initS) mapS[s]=0;
    for(auto s:S){
        char c=s.front();
        if(initS.count(c)) mapS[c]++;
    }

    int64_t ans=0;
    for(auto i=mapS.begin();i!=prev(mapS.end(),2);i++){
        int64_t numI=i->second;
        for(auto j=next(i);j!=prev(mapS.end());j++){
            int64_t numJ=j->second;
            for(auto k=next(j);k!=mapS.end();k++){
                int64_t numK=k->second;
                ans+=numI*numJ*numK;
            }
        }
    }

    cout<<ans<<endl;
}