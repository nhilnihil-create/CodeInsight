#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX 100005
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define ull long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define nl '\n'
#define zai <<' '<<
#define all(a) a.begin(),a.end()
#define pc __builtin_popcount
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	int n=s.size();
	int o=0,x=0;
	for(int i=0;i<n;i++){
		if(s[i]=='o')o++;
		else x++;
	}
	if(x<=7){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}