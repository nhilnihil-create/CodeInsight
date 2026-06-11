#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	string s;
	cin >> s;
	if(s=="zyxwvutsrqponmlkjihgfedcba"){
		cout << -1 << endl;
		return 0;
	}
	vector<bool> a(26);
	rep(i,s.size()){
		a[s[i]-97]= true;
	}
	if(s.size()==26){
		char c_max='a'-1;

		for(int i=s.size()-1;i>=0;i--){
			a[s[i]-'a']=false;
			if(s[i]<c_max&&i!=s.size()-1){
				//書き換え
				for(int j=s[i]-'a'+1;j<=26;j++){
					if(a[j]==0&&s[i]!=char('a'+j)){
						s[i]=char('a'+j);
						break;
					}
				}
				s.erase(i+1);
				break;
			}
			else{
				c_max = max(c_max,s[i]);
			}
		}
	}
	else{
		char add;
		rep(i,26){
			if(a[i]==0){
				add = 'a'+i; 
				break;
			}
		}
		s+=add;
	}
	cout << s << endl;
	return 0;
}

