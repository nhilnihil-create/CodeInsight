#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    rep(i,N) cin >> A[i]; sort(A.begin(),A.end());
    rep(i,N) cin >> B[i]; 
    rep(i,N) cin >> C[i]; sort(C.begin(),C.end());
    

    ll ans = 0;
    
    rep(i,N) {
	
	ll a = lower_bound(A.begin(),A.end(),B[i]) - A.begin();
	ll c = N - (upper_bound(C.begin(),C.end(),B[i]) - C.begin());
	ans += a*c;
//	cout << a << " " << c << endl;	
    }
    cout << ans << endl;

    
    return 0;
}

