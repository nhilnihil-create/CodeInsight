#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1145141919
typedef long long int ll;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

ll gcd( ll m, ll n )
{
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	while( m != n )
	{
		if ( m > n ) m = m - n;
		else         n = n - m;
	}
	return m;
}

ll lcm( ll m, ll n )
{
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	return ((m / gcd(m, n)) * n);
}

int main(){
    int a,b;
    cin >> a >> b;
    if(a+b==15){
        cout << "+" << endl;
    }else if(a*b==15){
        cout << "*" << endl;
    }else{
        cout << "x" << endl;
    }

    return 0;
}