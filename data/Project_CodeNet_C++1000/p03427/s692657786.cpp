#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int sum = 0;
	sum += ((int)s.size() - 1)*9;
    sum += (s[0] - '0') -1;

    int sum1 = 0;
    rep(i,(int)s.size()){
    	sum1 += s[i] - '0';
    }
	cout << max(sum,sum1) << endl;
}

// cout << fixed << setprecision(15) <<  << endl;