#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
ll A,B,C;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>A>>B>>C;
    cout<<((A==B && B==C)? "Yes":"No")<<endl;
}
