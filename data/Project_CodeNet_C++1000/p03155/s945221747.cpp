#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n, h, w,ans=0;
	cin >> n >> h >> w;
	ans = (n - h + 1)*(n - w + 1);
	cout << ans << endl;
}