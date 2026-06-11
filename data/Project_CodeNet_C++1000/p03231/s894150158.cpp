#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    ll N,M; cin>>N>>M;
    string S,T; cin>>S>>T;
    ll lcm=N/__gcd(N,M)*M;
    ll g=__gcd(N,M);

    /*vector<char>s(lcm,' ');
    vector<char>t(lcm,' ');
    ll cnts=0,cntt=0;
    rep(i,lcm){
        if(i%(lcm/N)==0&&cnts<=N-1){
            s[i]=S[cnts];
            cnts++;
        }
        if(i%(lcm/M)==0&&cntt<=M-1){
            t[i]=T[cntt];
            cntt++;
        }
         if(s[i]!=' '&&t[i]!=' '){
            if(s[i]!=t[i]){
                cout<<-1<<endl;
                return 0;
            }
        }
        if(cnts>=N&&cntt>=M)break;

    }
    cout<<lcm<<endl;*/
    for(int i=0,j=0;j<M;i+=N/g,j+=M/g){
        if(S[i]!=T[j]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<lcm<<endl;
}