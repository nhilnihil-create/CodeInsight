#include <bits/stdc++.h>
using namespace std;

  #define lp(start,finish) for(int i=start; i<finish; i++)
  #define read freopen("input.txt","r",stdin);
  #define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main(){
	//read
	int n,k;
	cin >> n >> k;
	int gap = 0;
	lp(1,n+1){
		gap++;
		i++;
	}
	if(gap>=k) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}