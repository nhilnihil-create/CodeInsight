#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <limits>
#include <ctype.h> 
#include <stdio.h> 
#include <set> 
#include <iomanip>
#include <cstdint>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '




int main() {
	int a = 0, b = 0;
	cin >> a >> b;
	int res = a+b;
	int res1 = a-b;
	int res2 = a*b;
	int ans = -10000;
	ans = max(ans,res);
	ans = max(ans,res1);
	ans = max(ans,res2);
	cout << ans << endl;

    return 0;
} 
