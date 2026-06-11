#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())

#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9+7:合同式の法
 
int main(){
    string s;
    cin >> s;

    ll MAX = 0;
    ll count = 0;
    REP(i,s.length()){
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
        count++;
        MAX = max(count,MAX);
        }
        else{
            count = 0;
        }
    }
    cout << MAX << endl;
    return 0;
}