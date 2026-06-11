#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll INF = 1e18;
const  ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define repd(i,n,init) for(ll i=(n);i>=init;i--)
#define repm(i,m) for(auto i=m.begin();i!=m.end();i++)

int main()
{
    string S;
    cin >> S;
    string target = "abc";
    ll length = S.length();
    repi(i,length,0){
        repi(j,target.length(),0){
            if(S.at(0) == target.at(j)){
                S.erase(S.begin());
                target.erase(target.begin()+j);
            }
        }
    }
    if(S.length() == 0){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}