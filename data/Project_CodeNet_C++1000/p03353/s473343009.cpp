#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll ans, mx, sum,temp, mn = 1e14, flag,cnt;





int main(){
	string s;
	cin>>s;
	ll q;
	cin>>q;
	set<string> s1;
	ll n=s.size();

	for(ll i=0; i<n; i++){
		string t;
		for(ll j=i; j<i+q; j++){
			if(j>=n) break;
			t+=s[j];
			s1.insert(t);
		}
	}

    set<string> :: iterator it;
    for(it=s1.begin(); it!=s1.end(); it++){
    	cnt++;
    	if(cnt==q){
    		cout<<*it;
    		return 0;
    	}
    }
	
}