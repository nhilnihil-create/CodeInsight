#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = n - 1; i>= 0; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
const int MAXN = 100005;
ll mod=1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int n=s.size();
	int ans=0;
	rep(i,n){
	    if(i%2){
            if(s[i]%2==0) ans++;
	    }
	    else{
            if(s[i]%2==1) ans++;
	    }
	}
	int cnt=0;
	rep(i,n){
        if(i%2){
            if(s[i]%2==1) cnt++;
        }
        else{
            if(s[i]%2==0) cnt++;
        }
	}
	cout<<min(ans,cnt);
    return 0;
}
