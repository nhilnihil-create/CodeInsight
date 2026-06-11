#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    bool ok = false;
    if(abs(a-c) <= d) ok = true;
    if(abs(a-b) <= d && abs(b-c) <= d) ok = true;
    cout << (ok?"Yes":"No") << endl;
}

    

