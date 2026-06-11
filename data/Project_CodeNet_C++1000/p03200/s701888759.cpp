#include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

int main(){
	string s;
	cin >> s;
	ll cnt_W = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='W') cnt_W++;
	}
	ll b_num=0;
	ll w_num=0;
	for(int i=0;i<s.size();i++){
		if(i<cnt_W){
			if(s[i]=='B') b_num+=i;
		}
		else
			if(s[i]=='W') w_num+=i;
	}
	cout << w_num-b_num << endl;
    return 0;
}