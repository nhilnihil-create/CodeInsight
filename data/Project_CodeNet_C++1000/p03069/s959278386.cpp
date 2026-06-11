#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
    int cnt=0;
	rep(i, n) {
		//黒の場所
		if (s[i] == '#') cnt++;
	}
	int ans = 1000000;
	int Lw = 0, Lb = 0;
	rep(i, n) {
		if (s[i] == '.') Lw++;
		else {
			int ansi = 0;
			ansi += Lb;
			ansi += (n - cnt) - Lw;
			ans = min(ans, ansi);
            Lb++;
		}
	}
    if(ans>cnt){
      cout<<cnt<<endl;
    }else{
      cout<<ans<<endl;
    }
}