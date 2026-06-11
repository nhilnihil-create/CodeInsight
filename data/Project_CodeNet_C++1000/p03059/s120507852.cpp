#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int a,b,t;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> a >> b >> t;
	cout << b * (t/a) << endl;

	cout.flush();
	return 0;
}