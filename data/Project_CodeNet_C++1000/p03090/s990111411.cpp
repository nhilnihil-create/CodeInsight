#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;
	map<pair<int,int>,bool> mp;
	vector<pair<int,int>> ans;
	if(n % 2 == 1){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(n - i != j && j != i && mp[P(i,j)] == false){
					ans.push_back(P(i,j));
					mp[P(i,j)] = true;
					mp[P(j,i)] = true;
				}
			}
		}
	}
	else{//n%2==0
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i + j != n + 1 && i != j && mp[P(i,j)] == false){
					ans.push_back(P(i,j));
					mp[P(i,j)] = true;
					mp[P(j,i)] = true;
				}
			}
		}
	}


	cout << ans.size() << endl;
	for(auto p:ans)cout << p.first << " " << p.second << endl;
}
