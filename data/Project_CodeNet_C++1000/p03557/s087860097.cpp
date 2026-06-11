#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

ll binarysearch(ll b[],ll i, ll n){
	//find the smallest index j such that b[j]>i
	ll k=n;
	for(int size=n;size>0;size/=2)
		while(k-size>=0 && b[k-size]>i)k-=size;
	return k;
}
ll binarysearch1(ll b[], ll i, int n){
	//find largest index k such that b[k]<i
	ll k=0;
	for(int size=n;size>0;size/=2)
		while(k+size<n && b[k+size]<i) k+=size;
	return k;
}

int main(){
	ll n;
	cin >> n;
	ll a[n],b[n],c[n];
	FOR(i,n){
		cin >>a[i];
	}
	FOR(i,n){
		cin >> b[i];
	}
	FOR(i,n){
		cin >> c[i];
	}
	ll sum=0;
	
	sort(a,a+n);
	//sort(b,b+n);
	sort(c,c+n);
	//cout << binarysearch(b,1,n);
	FOR(j,n){
		ll m=(lower_bound(a,a+n,b[j])-a);
		ll q=n-(upper_bound(c,c+n,b[j])-c);
		sum+=m*q;
	}
	cout << sum;
	/*cout <<"\n";
	sum=0;
	FOR(j,n){
		ll q=binarysearch1(a,b[j],n)+1;
		ll w=binarysearch(c,b[j],n);
		sum+=q*(n-w);
	}
	cout << sum;*/
	
	return 0;
}