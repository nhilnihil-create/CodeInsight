/*
题意是求一个序列中"所有子序列的中位数"所组成的序列的中位数 
看题解了，完全不会。https://www.cnblogs.com/quzhizhou/p/9535597.html  

首先我们先二分最后序列的中位数。设tot为中位数 >= mid的区间个数，若中位数序列的中位数 >= mid，
则有tot >= n(n+1)/4。
我们另外构造一个序列b[i], 当a[i]>=mid时b[i]=1, 否则bi=-1. 
那么若区间[l, r]的中位数 >= mid, 则b[l]+...+b[r] >= 0. 
于是我们求出序列b[i]的前缀和序列sum[i]，那么问题就变成了求满足l <= r且sum[r]-sum[l-1]>=0的数对(l,r)数量(0<=l,r<=n)，
这个问题可以用与求逆序对数量相似的方法解决. 树状数组即可. 
*/ 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int NN = 110000;
int a[NN], l, r, n, mid, ans;
int s[NN * 2];  
//树状数组，注意，[-n-1, n], 为了让每一个存的值都是>0, 都加上n即可（因为树状数组不能从0开始）
//所以开双倍空间给数组 

int lowbit(int x){
	return x & (-x);
} 

void add1(int x, int k){
	while (x <= n * 2){
		s[x] += k;
		x += lowbit(x);
	}
}

int getsum(int x){
	int sum = 0;
	while (x > 0){
		sum += s[x];
		x -= lowbit(x);
	}
	return sum;
}
/*
bool check(int mid){
	//memset(s, 0, sizeof(s));  //树状数组清0 
	 for(int i=1;i<=2*n;i++)s[i]=0;
	//与求逆序对的方法相同 
	add1(n, 1);  //因为在每个数的基础上都加了n，所以这句话相当于在和等于0的点+1
	long long sum = 0;
	long long tmp = 0;
	for (int i=1; i<=n; i++){
		if (a[i] >= mid) sum++;
		else sum--;
		tmp += getsum(sum + n);
		add1(sum + n, 1);
	} 
	long long nn = n * (n + 1) / 4; //注意！nn必须给long long 
	if (tmp >= nn) return true;
	else return false;
}*/ 

int check(int mid)
{
    for(int i=1;i<=2*n;i++)s[i]=0;
    ll tot=0, sum=0;
    add1(n,1);
    for(int i=1;i<=n;i++){
        sum+=(a[i]>=mid?1:-1);
        tot+=getsum(sum+n);
        add1(sum+n,1);
    }
//    printf("%d %lld\n",mid,tot);
    return tot>=1ll*n*(n+1)/4;
}

int main(){
	//freopen("atcoderarc101d.in", "r", stdin);
	
	scanf("%d", &n);
	l = 0x7fffffff; r = 0;
	for (int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if (a[i] >= r) r = a[i];
		if (a[i] <= l) l = a[i];
	}
	//printf("%d %d\n", l, r);
	while (l <= r){
		mid = (l + r) / 2;
		if (check(mid)){
			ans = mid; 
			l = mid + 1;
		} else r = mid-1;
	}
	printf("%d", ans);
	
	
	/*while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);*/
	
	return 0;
} 