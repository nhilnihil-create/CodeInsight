#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;


#define pb push_back
#define mp make_pair
#define F first
#define S second
const int inf = (int) 1e9;
const int maxn = 2 * 1e5 + 10 ;


int n,m;
int ans;




void solve(){
	scanf("%d\n" , &n);
	for(int i = 0; i < n; ++i){
		scanf("%d ", &m);
		ans += m - 1;
	}
	printf("%d\n", ans );
	
}

int main() 
{ 
	
   solve() ;   
} 






