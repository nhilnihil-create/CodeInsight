#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
vector<long long>A;
int check(long long k1){
	long long now=1,w=-1,k2=k1;
	int s=0;
	for (int i=1;i<=17;i++){
		if (k1%10!=9&&w==-1) w=now;
		s+=k1%10; k1/=10; now*=10;
	}
	long long k3=k2+w;
	return k2*(s+1)<=k3*s;
}
int main(){
	long long pre=0;
	for (int i=0;i<=15;i++){
		for (int j=0;j<=200;j++)
			if ((i||j)&&check(j*(pre+1)+pre)) A.push_back(j*(pre+1)+pre);
		pre=pre*10+9;
	}
	sort(A.begin(),A.end());
	A.resize(unique(A.begin(),A.end())-A.begin());
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++) cout<<A[i]<<endl;
}