#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359
#define eps 1e-8
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) FOR(i,0,n)
typedef long long int ll;
const int INF = 1<<29;
typedef long long ll;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double tick() { 
	static clock_t oldticks;
	clock_t newticks = clock();
	double diff = 1.0 * (newticks - oldticks) / CLOCKS_PER_SEC; 
	oldticks = newticks;
	return diff;
}

inline int toInt(string s){
	return atoi(s.c_str());
}

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

inline int lcm(int a,int b){
	return a*(b/gcd(a,b));
}

inline bool isPrime(int n){
	ll j;
	j=sqrt(n);

	if(n<2)
		return 0;
	for(int i=2;i<=j;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

inline long long nCr(long long n,long long m){
    ll res=1;
    if(n-m < m) m=n-m;

    for(ll i=1;i<=m;i++,n--){
        res=res*n;
        res=res/i;
    }
    return res;
}

int a,b;

int main(){
	ios_base::sync_with_stdio(false); //Fast I/O
	cin.tie(NULL);
	//freopen("in.txt","r",stdin);
	//freopen("output.txt","w",stdout);	

	cin >> a >> b;

	if(a+b==15)
		cout << '+';
	else if(a*b==15)
		cout << '*';
	else
		cout << "x";

    //cerr << tick();

	return 0;
	
}
