#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int res = 0;


    auto count = [&](string s) {
	int n = s.length();
	int res = 0;
	for (int i=0; i+1<n; i++) {
	    if (s[i]=='A' && s[i+1]=='B') res++;
	}
	return res;
    };

    int n;
    cin>>n;
    int A = 0; //...A
    int B = 0; //B...
    int BA = 0;
    while (n--) {
	string s;
	cin>>s;
	res += count(s);
	if (s[0]=='B' && s.back()=='A') {
	    BA++;
	} else if (s[0]=='B') {
	    B++;
	} else if (s.back()=='A') {
	    A++;
	}
    }


    bool aloaded = false;
    while (true) {
	if (!aloaded) {
	    if (A>0) {
		aloaded = true;
		A--;
	    } else if (BA>0) {
		BA--;
		aloaded = true;
	    } else {
		break;
	    }
	} else {
	    if (BA>0) {
		res++;
		BA--;
		aloaded = true;
	    } else if (B>0) {
		res++;
		B--;
		aloaded = false;
	    } else {
		break;
	    }
	}
    }

    cout<<res<<endl;    
    return 0;
}
