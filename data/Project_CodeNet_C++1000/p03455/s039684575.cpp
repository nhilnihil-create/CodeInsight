#include <bits/stdc++.h>
#include <algorithm>

#define REP(i,n) for(int i = 0;i < n;++i)
#define PB(s) push_back(s)
#define ST(n) sort(n.begin(),n.end())

using namespace std;
typedef long long ll;

int main(){
	int a,b;
	cin >> a >> b;
	if(a*b%2)
		cout << "Odd" << endl;
	else cout << "Even" << endl;
}