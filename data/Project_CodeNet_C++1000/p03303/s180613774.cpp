#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<complex>
#include<math.h>
using namespace std;
typedef long long int llint;
typedef vector<int> vint;
typedef vector<llint> vllint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<llint, llint>> vpllint;
#define rep(i,n) for(int i=0;i<n;i++)
#define yes(ans) if(ans)cout<<"yes"<<endl;else cout<<"no"<<endl;
#define Yes(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;

bool check(int a, int b) {
	return a > b;
}

int main() {
	char s[1010];
	cin >> s;
	int n;
	cin >> n;
	rep(i, strlen(s)) {
		if (i%n == 0) {
			cout << s[i];
		}
	}
	cout << endl;
	return 0;
}