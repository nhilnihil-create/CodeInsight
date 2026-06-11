#include <bits/stdc++.h>

#define vec(v) vector<int>(v)
#define be(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define mapci(mp) map<char*,int>(mp)
#define mapcc(mp) map<char*,char*>(mp)
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    ll g=__gcd(n,m),x=n/g*m;
    for(int i=0;i<=g;i++){
    	if(s[n/g*i]!=t[m/g*i]){
    		cout <<-1<<endl;
    		return 0;
    	}
    }
    cout <<x<<endl;
    return 0;
}
