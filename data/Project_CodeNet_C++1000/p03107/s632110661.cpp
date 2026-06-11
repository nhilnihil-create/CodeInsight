#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	string s, c = "01"; 
	pair<int,int> cont = {0,0};
	cin >> s;
	
	for(auto i : s){

		if (i==c[0]){
			if (cont.second) cont.second --;
			else cont.first++;
		}
		else{
			if (cont.first) cont.first --;
			else cont.second++;
		}
	}
	printf("%lu\n", s.size() - (cont.first + cont.second));
	return 0;
}
