#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
ll N;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>s;
    ll c=0;
    for(auto ch:s){
        if(ch=='R'){
            c++;
        }
    }
    cout<<(c>N-c?"Yes":"No")<<endl;
}
