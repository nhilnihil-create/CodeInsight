#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int D, N;
	cin  >> D >> N;
	int num;
	if(D==0) num = 1;
	else if(D==1) num = 100;
	else num = 10000;
	if(N==100) N++;
	cout << num * N << endl;


}








