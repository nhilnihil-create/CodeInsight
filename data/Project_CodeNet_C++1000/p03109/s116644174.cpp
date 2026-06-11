#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std; 

int main(){
	int y,m,d;
	scanf("%d/%d/%d", &y, &m, &d);
	if(y < 2019 || y == 2019 && m <= 4) {
      cout << "Heisei" << endl;
    } else {
      cout << "TBD" << endl;
    }
}
