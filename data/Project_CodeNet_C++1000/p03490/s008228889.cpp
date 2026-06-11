#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

int n ,X, Y;
string s;
vector<int> x, y;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> s >> X >> Y;
    n = s.size();
    bool b = true;
    int c = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'F') c++;
    	else{
    		if(c == 0){
    			b = !b;
    			continue;
    		}
    		if(b) x.pb(c);
    		else y.pb(c);
    		c = 0;
    		b = !b;
    	}
    }
    if(c > 0){
    	if(b) x.pb(c);
    	else y.pb(c);
    }
    if(s[0] == 'F'){
    	X -= x[0];
    	x.erase(x.begin());
    }
    map<int, bool> m;
    m[0] = true;
    for(int i = 0; i < x.size(); i++){
    	map<int, bool> m1 = m;
    	m.clear();
    	for(auto p : m1){
    		m[p.first + x[i]] = true;
    		m[p.first - x[i]] = true;
    	}
    }
    if(!m[X]){
    	cout << "No";
    	return 0;
    }
    m.clear();
    m[0] = true;
    for(int i = 0; i < y.size(); i++){
    	map<int, bool> m1 = m;
    	m.clear();
    	for(auto p : m1){
    		m[p.first + y[i]] = true;
    		m[p.first - y[i]] = true;
    	}
    }
    if(m[Y]) cout << "Yes";
    else cout << "No";
}