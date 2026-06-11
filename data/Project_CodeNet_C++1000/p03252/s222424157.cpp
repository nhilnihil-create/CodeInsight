#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int n;
string s, t;

map<char,set<char>> mp;
set<char> viz;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>s>>t;

    n = s.size();
    map<char,int> into;

    for (int i=0; i<n; i++) {
	mp[s[i]].insert(t[i]);
	if (!into.count(s[i])) {
	    into[s[i]];
	}
	into[t[i]]++;
    }

    for (auto p: mp) {
	int n = p.second.size();
	if (n != 1) out("No");
    }

    for (auto qq: into) {
	char c = qq.first;
	if (viz.count(c)) continue;
	if (qq.second>0) continue;
	bool cycle = true;
	while (!viz.count(c)) {
	    viz.insert(c);
	    if (!mp.count(c)) {
		cycle = false;
		break;
	    }
	    c = *mp[c].begin();
	}
	if (cycle) {
	    if (c != qq.first) {
		out("No");
	    }
	}

    }

    out("Yes");    
    
    return 0;
}
