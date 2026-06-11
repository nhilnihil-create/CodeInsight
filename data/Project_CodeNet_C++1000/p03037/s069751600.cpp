#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	long long int n, m, v1, v2;
    cin >> n >> m;

    long long int l[m], r[m];

    for (long long int i = 0; i < m; i++)
    {
    	cin >> l[i] >> r[i];
    }

    v1 = l[0];
    v2 = r[0];

    for (long long int i = 1; i < m; i++)
    {
    	v1 = max(v1, l[i]);
    	v2 = min(v2, r[i]);
    }

    if(v2 - v1 >= 0)
    {
    	cout << v2-v1+1;
    } 
    else
    {
    	cout << 0;
    }

	return 0;
}

