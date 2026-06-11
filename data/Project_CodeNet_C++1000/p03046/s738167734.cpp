#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

#define mkp make_pair
#define eb emplace_back
#define sz(s) (int)(s.size())
 
main (){
	clog << "Ready\n";
	
	int k, m;
	cin >> m >> k;
	
	if ((m == 1 && m == k) || (k >= (1 << m)))
        return cout << -1, 0;
    
    if (!k) {
        for (int i = 0; i < (1 << m); ++ i)
            cout << i << " " << i << " ";
        return 0;
    }
    
    cout << "0 " << k << " 0 ";
    
    for (int i = 1; i < (1 << m); ++ i)
        if (i != k)
            cout << i << " ";
    
    cout << k << " ";
    for (int i = (1 << m) - 1; i > 0; -- i)
        if (i != k)
            cout << i << " ";
	
	cerr << '\n';
	return 0;
}