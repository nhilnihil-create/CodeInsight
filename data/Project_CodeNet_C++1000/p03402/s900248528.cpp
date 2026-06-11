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
	int a,b;cin >> a >> b;
	a--;b--;
	vector<string> s(100);
	rep(i,100){
		s.at(i)="";
		rep(j,100){
			if(i<50) s[i]+='#';
			else s[i]+='.';
		}
	}
	for(int i=0;i<50;i+=2){
		bool flg=false;
		for(int j=0;j<100;j+=2){
			if(a==0){
				flg=true;
				break;
			}
			s[i][j]='.';
			a--;
		}
		if(flg) break;
	}
	for(int i=99;i>50;i-=2){
		bool flg=false;
		for(int j=0;j<100;j+=2){
			if(b==0){
				flg=true;
				break;
			}
			s[i][j]='#';
			b--;
		}
		if(flg) break;
	}
	cout << 100 << " " << 100 << endl;
	rep(i,100){
		cout << s.at(i) << endl;
	}
}