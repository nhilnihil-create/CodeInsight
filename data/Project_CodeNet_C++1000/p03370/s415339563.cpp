#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main(){
	int n,x;
	cin>>n>>x;
	int sum = 0;
	vector<int> m(n);
	int miniDonuts = 1000;
	for(int i = 0;i < n; i++){
		cin>>m[i];
		sum += m[i];
		miniDonuts = min(m[i],miniDonuts);
	}
	x = x - sum;
	cout<< (x / miniDonuts) + n<<endl;
	return 0;
}
