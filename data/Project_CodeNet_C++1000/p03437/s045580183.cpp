#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int x,y; cin>>x>>y;
	cout<<(x%y==0 ? -1 : x)<<endl;
	return 0;
}
