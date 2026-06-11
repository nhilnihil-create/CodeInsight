#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp(a, b) make_pair(a, b)
#define pb(t) push_back(t)
#define ft first
#define sc second
#define pt(num) cout << num << "\n"
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;




int main(void) {
    string s;
    cin >> s;
    ll cnt[3]={};
    ll i;
    ll f=3;
    
    for(i=0; i<s.size(); i++) {
        cnt[s[i]-'a']++;
    }
    
    for(i=0; i<3; i++) if(cnt[i]==0) f--;
    
    if(f==1) {
        if(s.size()<2) pt("YES");
        if(s.size()>=2) pt("NO");
    }else if(f==2) {
        if(s.size()<3) pt("YES");
        if(s.size()>=3) pt("NO");
    }else if(f==3) {
        ll max=max(cnt[0], max(cnt[1], cnt[2]));
        ll min=min(cnt[0], min(cnt[1], cnt[2]));
        if(max<=min+1) pt("YES");
        else pt("NO");
    }
    
}
