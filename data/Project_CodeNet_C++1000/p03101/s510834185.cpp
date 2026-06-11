#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;


int main(){
	int H,W;
	int h,w;
	cin >> H >> W;
	cin >> h >> w;
	cout << H*W -(W*h) -(H-h)*w<< endl;

	return 0;
}