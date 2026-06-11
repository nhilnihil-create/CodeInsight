#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b; cin>>a>>b;
	if(a<=5)cout<<0<<endl;
	else if(a>=6 && a<=12)cout<<b/2<<endl;
	else cout<<b<<endl;
	return 0;
}
