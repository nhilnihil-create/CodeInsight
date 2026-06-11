#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;

    pair<int,int> T=make_pair(0,N);
    cout<<0<<endl;
    string s; cin>>s;
    if(s=="Vacant") return 0;

    map<int,string> mp;
    mp[0]=s;
    mp[N]=s;

    rep(i,0,19){
        int q=(T.second-T.first)/2+T.first;
        cout<<q<<endl;
        string s; cin>>s;
        if(s=="Vacant") return 0;

        mp[q]=s;
        if((q-T.first)%2){
            if(s==mp[T.first]) T.second=q;
            else T.first=q;
        }else{
            if(s!=mp[T.first]) T.second=q;
            else T.first=q;
        }
    }
}