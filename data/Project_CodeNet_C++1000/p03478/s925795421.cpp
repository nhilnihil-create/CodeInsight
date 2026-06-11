#include <bits/stdc++.h>
#define rep(i,n) for (unsigned int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

const double PI = acos(-1);

unsigned long long GetDigit(unsigned long long num){
    return std::to_string(num).length();
}

int main()
{
	int n,a,b; cin >> n >> a >> b;
	int i = 1;
	int tmp1,tmp2,tmp3,tmp4,tmp,ans=0;
	while(i<=n) {

		tmp1 = i/10000;
		tmp2 = (i-tmp1*10000)/1000;
		tmp3 = (i-tmp1*10000-tmp2*1000)/100;
		tmp4 = (i-tmp1*10000-tmp2*1000-tmp3*100)/10;

		tmp = tmp1+tmp2+tmp3+tmp4+ i%10;

		if(tmp>=a && tmp<=b) {
 			ans += i;
		}
		i++;
	}
	cout << ans << endl;
}
