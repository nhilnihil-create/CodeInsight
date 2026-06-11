#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define MAX_T 1001
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
const ll DEP = 1e18;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int t;
//解説AC;
long long gcd(ll x,ll y){
    ll r = x % y;
    while(r != 0){
        x = y;
        y = r;
        r =x % y;
    }
    return y;
}
void check(ll a,ll b,ll c,ll d){
    if(a < b){
        cout << "No" << endl;
        return;
    }
    if(b > d){
        cout << "No" << endl;
        return;
    }
    ll g = gcd(d,b);
    ll mx = b - g + (a%g);
    if(mx > c){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    return;
}
ll A,B,C,D;
int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> A >> B >> C >> D;
        check(A,B,C,D);
    }
    return 0;
}
