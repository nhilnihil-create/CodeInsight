#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;


int main()

{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	char n, m; cin >> n >> m;
	if ((int)n > (int)m)
		cout << '>' << endl;
	else if ((int)n < (int)m)
		cout << "<" << endl;
	else cout << '=' << endl;
	return 0;

}