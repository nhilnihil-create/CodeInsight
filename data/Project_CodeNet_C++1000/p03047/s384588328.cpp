#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Pll;
typedef pair<P,P> PP;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define repr(i,a,n) for(ll i = n-1;i >= a;i--)
#define LINF (ll)1e17
#define INF (int)1e9
#define MOD (ll)1e9+7
#define sMOD 1e5
#define fs first
#define sc second

ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
	
}

void YNout(bool check){
	if(check)cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return;
}

void Yayout(bool check){
	if(check) cout << "Yay!" << endl;
	else cout << ":(" << endl;
	
	return;
}

/*
template <typename T>
void vecout(vector<T>& vecout_vec){
	
	rep(i,0,vecout_vec.size()){
		cout << vecout_vec.at(i) << endl;
	}
	
	return ;
}

template <typename T>
void vecin(vector<T>& vecin_vec, ll n){
	
	ll temp ;
	
	rep(i,0,n){
		cin >> temp;
		vecin_vec.push_back(temp);
		
	}
}

template <typename T>
void in(T& literal_in, T& literal_in2, ...){
	cin >> literal_in;
	in(literal_in2, ...);
	
	return;
}

template <typename T>
void in(T& literal_in){
	
	cin >> literal_in;
	
	return;
}

template <typename T>
void out(T& literal_out, T& literal_out2, ...){
	cout << literal_out << endl;
	out(literal_out2, ...);
	
	return;
}

template <typename T>
void out(T& literal_out){
	
	cout << literal_out << endl;
	
	return;
}
*/
signed main(){
	ll k,n;
	
	cin >> n >> k;
	cout << n-k+1 << endl;
	
	
	
	return 0;
}
