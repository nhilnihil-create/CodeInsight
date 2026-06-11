#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
bool isPrime[1000002];

int main()
{
	int N;
	int H;
	cin>>N>>H;
	vector<int> a(N);
	vector<int> b(N);
	for(int i = 0; i < N; i++){
		cin>>a[i]>>b[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());
	int usualAttack = a[0];
	int ans = 0;
	for(int i = 0;i < N && b[i] >= usualAttack; i++){
		H = H - b[i];
		ans++;
		if( H <= 0) break;
	}
	//cout<<"nokori:"<<H<<",usualAttack:"<<usualAttack<<endl;
	if( H <= 0){
		//do nothing
	}else if( H % usualAttack == 0){
		ans = ans + (H/usualAttack);
	}else{
		ans = ans + (H/usualAttack) + 1;
	}
	cout<<ans<<endl;
	return 0;
}

