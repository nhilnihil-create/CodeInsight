#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int c[4];

int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		c[s[i]-'a']++;
	}
	int ma = max(c[0],max(c[1],c[2]));
	bool flag = 1;
	for(int i=0;i<3;i++){
		if(abs(ma-c[i])>1){
			flag = 0;
		}
	}
	if(flag){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}