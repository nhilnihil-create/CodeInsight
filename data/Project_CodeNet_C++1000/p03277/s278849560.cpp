#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define pill pair<int, int>
#define mst(a, b)    memset(a, b, sizeof a)
#define REP(i, x, n)    for(int i = x; i <= n; ++i)
#define INF 0x3f3f3f3f
#define ll long long
#define pi acos(-1.0)
int a[110000];
int sum[110000];
int temp[110000];
LL t1 = 0 ,t2 = 0;
int n;
void MergeSort(int l,int r){
//	puts("ca");
	if (l == r)return ;
	int mid = (l+r)>>1;
	MergeSort(l,mid);
	MergeSort(mid+1,r);
	int p = l, q = mid + 1,k = l;
	while(p <= mid && q <= r){
		if(sum[p] < sum[q]){
			temp[k++] = sum[p++];
		}else{
			t1 += (p-l);
			temp[k++] = sum[q++];
		}
	}
	while(p <= mid){
		temp[k++] = sum[p++];
	}
	while(q <= r){
		t1 += (p-l);
		temp[k++] = sum[q++];
	}
	for(int i = l ; i <= r ; i++){
		sum[i] = temp[i];
	}
}
bool Check(int x){
	t1 = 0;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] <= x){
			sum[i] = 1;
		}else{
			sum[i] = -1;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		sum[i] += sum[i-1];
	}
	MergeSort(0,n);
	return t1 >= (t2/2+1);
}
int main(){
	int L = 1100000000,R = -1100000000;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
		L = min(L,a[i]);
		R = max(R,a[i]);
		t2 += i;
	}//t2存总的区间个数
	while(L < R){
		int mid = (L+R)>>1;
		if(Check(mid))R = mid ;
		else L = mid + 1;
	}
	printf("%d\n",L);
}
/*
10
5 9 5 9 8 9 3 5 4 3
3
10 30 20
*/