#include<iostream>
#include<vector>
#include<algorithm>
#include <bitset>
using namespace std;


bool ok(vector<int> &v,int g){
	bitset<32000> cur;
	cur[16000] = 1;
	//cout << cur <<endl;
	for(int i=0;i<v.size();++i){
		cur = ((cur << v[i]) | (cur >> v[i]));
	}
//	cout << cur <<endl;
//	cout << cur[8000+g] <<endl;
	return cur[16000+g];
}

int main(){
	string s;
	int gx,gy;
	cin >> s;
	cin >> gx >> gy;
	
	
	int cnt  = 0;
	int fn = 0;
	vector<int> vy,vx;
	for(int i=0;i<s.size();++i){
		if(s[i] == 'F'){
			fn++;
		}
		if(s[i] == 'T' || i == s.size()-1){
			if(cnt%2==0){
				if(cnt == 0){
					gx -= fn;
				}else{
					vx.push_back(fn);
				}
			}else{
				vy.push_back(fn);
			}
			fn = 0;
			cnt++;
		}
	}
	
	if(ok(vx,gx) && ok(vy,gy)){
		cout << "Yes" <<endl;
	}else{
		cout << "No" <<endl;
	}
	
	
	
	return 0;
}
