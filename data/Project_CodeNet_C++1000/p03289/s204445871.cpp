#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define space " "
#define MOD (long long) 1000000007
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* variable_name, T&& value){cout << variable_name << ": " << value << endl;}
template <typename T1, typename... T2> void __f(const char* names, T1&& arg1, T2&&... args){const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << ": " << arg1 << " |";__f(comma + 1, args...);}

const ll N = 5e5 + 5;
ll *v;
ll n;

void solve(){
    string s; cin >> s;
	bool poss = true;
	if(s[0] == 'A'){
		for(auto i : s)
			if(i != 'A' && i != 'C'){
				if(islower(i))
					continue;
				poss = false;
				break;
			}
		int cnt = 0;
		for(int i = 2; i <= s.length() - 2; i++)
			if(s[i] == 'C')
				cnt++;
		if(cnt != 1)
			poss = false;
	}else
	{
		poss = false;
	}
	if(poss)
		cout << "AC" << endl;
	else
		cout << "WA" << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    // cout << "\n\nBLAH BLAH BLAH\n\n";
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}