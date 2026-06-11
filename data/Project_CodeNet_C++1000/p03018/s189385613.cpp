#define _GLIBCXX_DEBUG

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

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

    
    ll n = s.size();
    REP(i,n-1){
        if(s[i]=='B' && s[i+1]=='C'){
            s[i] = 'D';
            s[i+1] = 'd';
        }
    }
    
    ll ans=0, cnta=0;
    REP(i,n){
        if(s[i]=='B'||s[i]=='C'){
            cnta=0;
        }
        else if(s[i]=='A'){
            cnta++;
        }
        else if(s[i]=='D'){
            ans += cnta;
        }
    }
    cout << ans << endl;

    /*
    ll count=0;
    while(1){
        ll itr = s.find("ABC");
        if(itr == string::npos){
            break;
        }
        //cout << itr << endl;
        s.replace(itr,3,"BCA");
        count++;
    }
    cout << count << endl;
    */
    return 0;
}