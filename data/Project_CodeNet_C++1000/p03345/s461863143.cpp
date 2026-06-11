#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <iterator>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int INF = 1e9 + 5;

int main() {
	ll a = 0, b = 0, c = 0, k = 0;
	cin >> a >> b >> c >> k;
	if(k % 2 != 0){
		cout << b-a << endl;
	}
	else{
		cout << a - b << endl;
	}



	

    return 0;
} 