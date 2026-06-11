#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101010;
int main(){
	int a,b;
	cin>>a>>b; 
	if(a+b==15){
		cout<<"+";
	}
	else{
		if(a*b==15){
			cout<<"*";
		}
		else{
			cout<<"x";
		}
	}
	return 0;
}  