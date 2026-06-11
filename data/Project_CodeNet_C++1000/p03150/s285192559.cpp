#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
using namespace std;
typedef long long llint;
typedef long double ld;
#define inf 1e18

llint n;
string s;
void solve(){
	cin >> s;
	if(s=="keyence"){
		cout << "YES" << endl;
	}
	else{
		bool f=false;
		for(int i=0;i<s.size();i++){
			if(f)break;
			for(int j=0;j<s.size();j++){
				if(i>j)continue;
				if(s.substr(0,i)+s.substr(j+1)=="keyence"){
					cout << "YES" << endl;
					f=true;
					break;
				}
			}
		}
		if(!f)cout << "NO" << endl;
	}

}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
