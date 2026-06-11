#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n , x , a;
bool flag;
vector<int>v , s;
bool cek(){
	while(s.size() > 0){
		flag = false;
		for(int i = s.size() - 1 ; i >= 0 ; i--){
			if(s[i] == i + 1){
				v.pb(s[i]);	
				s.erase(s.begin()+i);
				flag = true;
        break;
			}
		}
		if(!flag){
			v.clear();
			v.pb(-1);
			return false;
		}
	}
	return true;
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
        cin >> x;
        s.pb(x);
	}
	if(!cek()){
		cout << -1 << endl;
		return 0;
	}
	for(int i = v.size() - 1 ; i >= 0 ; i--){
		cout << v[i] << endl;
	}
}
// soal I analysis 1