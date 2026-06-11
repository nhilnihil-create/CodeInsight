/*
ID: markusz1
TASK: template
PROG: template
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ul;
typedef priority_queue<int> p_int;
typedef priority_queue<ll> p_ll;
typedef priority_queue<double> p_double;

int a,b,c;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
		if (c <= a+b+1)cout << b+c << endl;
		else cout << a+2*b+1 << endl;

}