#include<bits/stdc++.h>
using namespace std;
 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define lb(v,n) lower_bound(v.begin(),v.end(),n)
#define ub(v,n) upper_bound(v.begin(),v.end(),n)
#define mae(v) max_element(v.begin(),v.end())
#define mie(v) min_element(v.begin(),v.end())
#define INF 0x7FFFFFFF
#define mod 1000000007
typedef long long ll;
////////////////////////////////////////////////////////////

long nCr(long n, long k) {
    long r = 1;
    for (long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main(){
	int n;
	cin >> n;
	vector<ll> a;
	rep(i,0,n){
		int ta;
		cin >> ta;
		a.push_back(ta);
	}
	vsort(a);
	ll M = a[a.size()-1];
	
	if( M%2 ){
		int l_idx = lb(a,M/2)-a.begin();
		int u_idx = ub(a,M/2)-a.begin();
		//cout << l_idx << " " << u_idx << endl;
		if(u_idx == n-1 ) u_idx--;
		if( a[l_idx] == M/2 ) cout << M << " " << a[l_idx] << endl;
		else if( a[l_idx+1] == M/2+1 ) cout << M << " " << a[l_idx+1] << endl;
		else{
			if( M/2 - a[l_idx-1] < a[u_idx] - M/2 ) cout << M << " " << a[l_idx-1] << endl;
			else cout << M << " " << a[u_idx] << endl;
		}
		
	}
	else{
		int l_idx = lb(a,M/2)-a.begin();
		int u_idx = ub(a,M/2)-a.begin();
		if(u_idx == n-1 ) u_idx--;
		//cout << l_idx << " " << u_idx << endl;
		if( a[l_idx] == M/2 ) cout << M << " " << a[l_idx] << endl;
		else{
			if( M/2 - a[l_idx-1] < a[u_idx] - M/2 ) cout << M << " " << a[l_idx-1] << endl;
			else cout << M << " " << a[u_idx] << endl;
		}
	}
		
	ret 0;
}