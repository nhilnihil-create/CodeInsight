#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    string s;
    cin>>n>>s;
    int a[26]={0};
    for(int i=0;i<n;i++){
    	a[s[i]-'a']++;
    }
    ll ans=1;
    for(int i=0;i<26;i++){
    	//cout << a[i]<<endl;
    	ans*=(a[i]+1);
    	ans%=mod;
    }
    cout << ans-1<<endl;
    return 0;
}
