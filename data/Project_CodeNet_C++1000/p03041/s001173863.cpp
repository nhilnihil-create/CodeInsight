#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define first F
#define second S
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin>>n>>k;
	string s; cin>>s;
	s[k-1] = tolower(s[k-1]);
	cout<<s<<endl;
	return 0;
}
