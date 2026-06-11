#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int n,m;
int a[100010];

int main(){
	cin >> n;
	repp(i,0,n){
		cin >> a[i];
		m = max(m,a[i]);
	}
	int p = -1;
	repp(i,0,n) if(a[i] != m && abs(m-2*a[i]) < abs(m-2*p)) p = a[i];
	cout << m << ' ' << p << endl;
	return 0;
}
