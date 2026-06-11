#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	int n=s.size();
	vector<int> a(3);
	rep(i,n) a.at(s.at(i)-'a')++;
	int num=0;
	rep(i,3) if(a.at(i)) num++;
	if(n==1) cout << "YES" << endl;
	else if(n==2){
		if(num==2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else{
		if(num<3) cout << "NO" << endl;
		else{
			if(max(abs(a.at(0)-a.at(1)),max(abs(a.at(1)-a.at(2)),abs(a.at(2)-a.at(0))))<=1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
