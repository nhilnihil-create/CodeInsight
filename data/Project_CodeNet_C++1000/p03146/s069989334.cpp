#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
	int s;
	cin >> s;
	map<int,int> mp;
	int now = s;
	mp[s]++;
	int id = 1;
	while(1){
		if (now%2 == 0){
			if (mp.count(now/2)){
				cout << id+1 << endl;
				return 0;
			}
			else mp[now/2]++;
			now /=2;
			id++;
		}
		else {
			if (mp.count(now*3 + 1)){
				cout << id+1 << endl;
				return 0;
			}
			else mp[now*3+1]++;
			now = now*3 + 1;
			id++;
		}
	}
	
	
	return 0; 
}

