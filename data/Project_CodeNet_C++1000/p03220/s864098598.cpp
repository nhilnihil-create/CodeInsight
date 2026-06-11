#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,t,a;
	cin >> n >> t >> a;
	double ans = 1000000000;
    int minnum;
	rep(i,n){
		int h;
		cin >> h;
		double temp = t - h * 0.006;
        if(ans > abs(temp-a)){
            ans = abs(temp-a);
            minnum = i+1;
        }
	}
	cout << minnum << endl;
}