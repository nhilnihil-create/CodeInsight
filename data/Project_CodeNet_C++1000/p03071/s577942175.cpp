#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n,m, cnt = 0;
	cin >>n >> m;
  	if(n>=m) {
    	cnt += n;
      	n--;
    } else {
      	cnt += m;
      	m--;
    }
  	if(n>=m) {
    	cnt += n;
      	n--;
    } else {
      	cnt += m;
      	m--;
    }
  
  
	cout << cnt << endl;
}
