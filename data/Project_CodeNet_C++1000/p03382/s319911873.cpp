#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<int> a(n);
	int ma=0;
	rep(i,n){
		cin >> a.at(i);
		ma=max(ma,a.at(i));
	}
	int x=ma,y=0,d=1000000000;
	ma=ma/2;
	rep(i,n){
		if(a.at(i)>ma){
			if(a.at(i)==x) continue;
			if(a.at(i)-(ma+1)<d){
				d=a.at(i)-(ma+1);
				y=a.at(i);
			}
		}
		else if(a.at(i)<ma){
			if(ma-a.at(i)<d){
				d=ma-a.at(i);
				y=a.at(i);
			}
		}
		else{
			d=0;
			y=a.at(i);
			break;
		}
	}
	cout << x << " " << y << endl;
}