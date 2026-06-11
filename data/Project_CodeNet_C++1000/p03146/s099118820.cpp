#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int s;
	cin >> s;
	map<double,int> mp;
	int i = 1;
	while(1){
        //cout << s << endl;
		if(mp[s] == 1){
			cout << i << endl;
			return 0;
		}else{
            mp[s] = 1;
            i++;
			s = (s % 2 == 0) ? (s/2) : (3*s+1);
		}
	}
}