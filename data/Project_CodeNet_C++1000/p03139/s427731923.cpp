#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int a,b,n;
	cin >> n >> a >> b;
	

	cout << min(a,b) << " " << max(0ll,(a+b)-n) << endl;

	return 0;
}
