#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = ((ll)(x) - 1); i >= 0; i--)

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}
/*bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}*/

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

const ll mod = 1e9 + 7;
const ll IMF = 1LL<<29;
const double PI = 3.14159265358979323846;


// ******************************CODE**********************************//




int a,b;
char mp[101][105];

int main(){
        cin >> a >> b;
        for(int i = 1; i <= 50; i++)
        {
                for(int j = 1; j <= 100; j++)
                {
                        mp[i][j] = '.';
                }
        }
        for(int i = 51; i <= 100; i++)
        {
                for(int j = 1; j <= 100; j++)
                {
                        mp[i][j] = '#';
                }
        }

        b--;
        for(int i = 1; i <= 50 && b; i += 2)
        {
                for(int j = 1; j <= 100 && b; j += 2)
                {
                        mp[i][j] = '#';
                        b--;
                }
        }

        a--;
        for(int i = 100; i > 50 && a; i -= 2)
        {
                for(int j = 1; j <= 100 && a; j += 2)
                {
                        mp[i][j] = '.';
                        a--;
                }
        }

        cout << "100 100" << endl;
        for(int i = 1; i <= 100; i++){
                for(int j = 1; j <= 100; j++){
                        cout << mp[i][j];
                }
                cout << endl;
        }

        return 0;

}
