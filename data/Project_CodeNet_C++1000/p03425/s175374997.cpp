#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 1e5 + 5;
string s;int n;ll m = 0,a = 0, r = 0, c = 0, h = 0;
int P [10]={0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2};
int Q [10]={1 ,1 ,1 ,2 ,2 ,3 ,2 ,2 ,3 ,3};
int R [10]={2 ,3 ,4 ,3 ,4 ,4 ,3 ,4 ,4 ,4};

ll largest(ll a, ll b){
	return (a<b)?b:a;
}
ll smallest(ll a, ll b){
	if(a < b)return a;
	return b;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> s;
		if(s[0] == 'M')m++;
		if(s[0] == 'A')++a;
		if(s[0] == 'R')++r;
		if(s[0] == 'C')++c;
		if(s[0] == 'H')++h;
	}
	ll d[5];
	d[0] = m, d[1] = a, d[2] = r, d[3] = c, d[4] = h;
	ll ans = 0;
	for(int i = 0; i < 10; ++i){
		ans+=d[P[i]]*d[Q[i]]*d[R[i]];
	}
	cout << ans << endl;


    return 0;
}
