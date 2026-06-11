#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; char n;
	for (int i=0; i<4; i++)
		cin>>n, s+=n;
	sort (s.begin(),s.end());
	cout<<(s=="1479"?"YES":"NO")<<endl;
	return 0;
}
