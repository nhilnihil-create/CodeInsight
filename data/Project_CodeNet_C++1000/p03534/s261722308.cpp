#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	map<char,int> m;

	string s;
	cin >> s;
	rep(i,s.size()){
		m[s[i]]++;
	}

	vector<int> v;
	for(auto i : m){
		v.emplace_back(i.second);
	}
	sort(all(v), greater<int>());


	int len = s.size();
	while(true){
		rep(i,3){
			if(v[i] == 0){
				goto END;
			}else{
				v[i]--;
				len--;
			}
		}
	}
END:
	cout << (len == 0 ? "YES" : "NO") << endl;
}
