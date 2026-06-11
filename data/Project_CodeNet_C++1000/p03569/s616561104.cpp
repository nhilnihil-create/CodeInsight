#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	deque <char>a;
	for(ll i=0;i<s.size();i++){
		a.push_back(s[i]);
	}
	bool ch=true;
	ll ans=0;
	while(ch){
		if(a.size()==1||a.size()==0){
			
			break;
		}
		ch=false;
		if(a.front()==a.back()){
			ch=true;
			a.pop_front();
			a.pop_back();
		}
		else if(a.front()=='x'){
			ch=true;ans++;
			a.pop_front();
		}
		else if(a.back()=='x'){
			ch=true;ans++;
			a.pop_back();
		}
	}
	if(a.size()==0||a.size()==1){
	cout << ans;
	}
	else{
		cout << "-1";
	}
	// your code goes here
	return 0;
}