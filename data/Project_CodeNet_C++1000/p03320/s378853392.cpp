#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	vector<long long>a;
	int n, k;
	long long x, s1;

	f(j, 9){
		a.push_back(j + 1);
	}
	s1 = 1;
	f(i, 14){
		s1 = s1 * 10;
		f(j, 9){
			a.push_back(s1*(j + 2) - 1);
		}
	}
	k = 0;
	s1 = 1;
	while (k < 13){
		k++;
		s1 = s1 * 10;
		x = 1;
		for (;;){
			if ((x / 10) + (x % 10) + (9 * (k + 1)) < (10 * (x + 1)))break;
			f(j, 9){
				a.push_back(((10 * x) + j + 1)*s1 - 1);
			}
			x++;
		}
	}
	sort(a.begin(), a.end());

	scanf("%d", &n);
	f(i, n)printf("%lld\n", a[i]);

	return 0;
}