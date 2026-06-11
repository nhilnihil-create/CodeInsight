#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include <map>
using namespace std;
typedef long long int ll;
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define all(u) u.begin(),u.end()
#define pl pair<ll,ll>
#define fi first
#define se second
#define inf 1000000007

string S;
ll N;
ll ans;

int main() {
    cin >> S;
    N = S.size();
    if (N % 2){
        ll mid = (N-1)/2;
        char m = S[mid];
        ans = N/2 + 1;
        ll d = 1;
        while(mid-d >= 0 && (S[mid-d] == m && S[mid+d] == m)){
            ans++;
            d++;
        }
    }
    else{
        ll mid = N/2;
        char m = S[mid];
        char n = S[mid-1];
        ans = N/2;
        ll d = 0;
        while((mid+d < N) && (S[mid+d] == m && S[mid-1-d] == m)){
            ans++;
            d++;
        }
    }
    cout << ans << endl;
    return 0;
}
