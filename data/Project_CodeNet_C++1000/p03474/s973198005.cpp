//
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MOD 1000000007
#define PI 3.14159265
#define EPS 1e-9
#define Pi acos(-1.0)
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define forn(i,n) forr(i,0,n)
#define PB push_back
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

/*CODE START HERE*/

int a, b;
string s;
bool sol;

int main(){
    ios::sync_with_stdio(0);
    cin >> a >> b;
    cin >> s;
    sol = true;

    if((int)s.length() != a+b+1) sol = false;

    forn(i,(int)s.length()){
        if(i == a){
            if(s[i] != '-'){
                sol = false;
            }
            continue;
        }

        if(s[i] < '0' || s[i] > '9'){
            sol = false;
        }
    }

    if(sol){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}