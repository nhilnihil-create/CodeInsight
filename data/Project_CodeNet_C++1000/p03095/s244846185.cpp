#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 1e5 + 5;

char s[N];
int cnt[33];

signed main(){
    int n;
	scanf("%lld %s", &n, s+1);	
    
    for(int i=1; i<=n; i++)
        cnt[ s[i]-'a' ]++;
    
    int ans = 1;
    for(int i=0; i<26; i++)
        ans = ans * (cnt[i] + 1) % mod;
    
    cout << ans - 1;
    return 0;
}