#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)

int main(){
    int N; cin>>N;
    string S; cin>>S;

    map<char,int> mapS;
    for(auto s:S) mapS[s]++;

    map<char,int> mapSubS;
    int ans=0;
    rep(i,0,N-1){
        int _ans=0;
        mapSubS[S.at(i)]++;
        for(auto _s:mapSubS){
            if(mapS[_s.first]-_s.second>0) _ans++;
        }

        ans=max(ans,_ans);
    }

    cout<<ans<<endl;
}
