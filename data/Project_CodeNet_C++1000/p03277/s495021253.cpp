#include<bits/stdc++.h>
#define ff(i, x, y) for(int i = x;i <= y;i++)
using namespace std;
typedef long long ll;
int n, pre[100010], mes[100010], ans, bit[200010], cnt;
ll sum;
//map<int, int>mp;
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int x)
{
    while(i<=n + 100005)
    {
        bit[i]+=x;
        i+=lowbit(i);
    }
	return;
}
void sub(int i,int x)
{
    while(i<=n + 100005)
    {
        bit[i]-=x;
        i+=lowbit(i);
    }
	return;
}
int qsum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=lowbit(i);
    }
    return s;
}
bool check(int x) {
	ll tmp = 0;
	ff(i, 1, n) {
		if(mes[i] <= x)
			pre[i] = -1;
		else
			pre[i] = 1;
		pre[i] += pre[i - 1];
	//	bit[i] = bit[i + 100005] = 0;
	}
	ff(i, 1, 200005)
		bit[i] = 0;
	add(100005, 1);
	ff(i, 1, n) {
		tmp = tmp + i - qsum(pre[i] + 100005);
		add(pre[i] + 100005, 1);
	//	cout << tmp << endl;
	}
	//cout << "     " << x << "     " << tmp << endl;
	//cout << tmp << endl;
	if(tmp >= sum / 2 + 1)
		return true;
	return false;
}
int main() {
	scanf("%d", &n);
	sum = (n + 1);
	sum = sum * n / 2;
	ff(i, 1, n) {
		scanf("%d", &mes[i]);
		//pre[i] = mes[i];
	}
	int l = 0, r = 1e9 + 7, mid = (l + r) / 2;
	//cout << mid << endl;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else 
			l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;	
}