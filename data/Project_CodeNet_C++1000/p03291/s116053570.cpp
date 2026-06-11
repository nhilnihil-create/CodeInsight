#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    ll count[3];
    count[0]=0;
    count[1]=0;
    count[2]=1;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            count[0]+=count[2];
        }
        if(s[i]=='B'){
            count[1]+=count[0];
            count[1]%=MOD;
        }
        if(s[i]=='C'){
            ans+=count[1];
            ans%=MOD;
        }
        if(s[i]=='?'){
            ll temp1=count[0], temp2=count[1], temp3=ans, temp4=count[2];
            count[0]+=temp4;
            count[0]+=temp1*2;
            count[0]%=MOD;
            count[1]+=temp1;
            count[1]+=temp2*2;
            count[1]%=MOD;
            ans+=temp2;
            ans%=MOD;
            ans+=temp3*2;
            ans%=MOD;
            count[2]*=3;
            count[2]%=MOD;
        }
    }
    cout << ans << "\n";
}