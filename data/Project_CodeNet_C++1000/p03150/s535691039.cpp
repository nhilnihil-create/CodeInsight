#include<bits/stdc++.h>
#define REP(i,x) for(int i=0,i##_len=(x);i<i##_len;++i)
#define rep(i,a,b) for(int i=(a),i##_len(b);i<i##_len;++i)
#define All(x) begin(x),end(x)
#define rAll(x) rbegin(x),rend(x)
using namespace std;
using ll = long long;

int main(){
    string s;cin>>s;
    REP(i,s.size()) rep(j,i,s.size()+1){
        string t=s;
        t.erase(t.begin()+i,t.begin()+j);
        if(t=="keyence"){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
