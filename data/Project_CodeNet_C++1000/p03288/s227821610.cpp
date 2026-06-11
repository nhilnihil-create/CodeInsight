#include <bits/stdc++.h>
 
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define INF 999999999
#define MOD 1000000007
 
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
 
int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};
 
int r;
 
int main(){
	cin >> r;
	if(r < 1200){
		cout << "ABC" << endl;
	}else if(r < 2800){
		cout << "ARC" << endl;
	}else{
		cout << "AGC" << endl;
	}
	return 0;
}
