#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int maxn=5000010;
bitset<maxn>bs;
int a[2010];
int n,sum;
int main(){
	cin>>n;
	bs[0]=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		bs|=(bs<<a[i]);
	}
	do sum++;while(!bs[sum/2]);
	// while(!bs[sum/2])sum++;
	cout<<sum/2<<endl;
}
