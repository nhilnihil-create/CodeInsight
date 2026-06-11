#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N = 200010;
int ans[26];
int a[N];
int n;
ll pos = 0,cnt = 0;

int main () {
	scanf("%d",&n);
	int k = 1;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		int flag = 1;
        for (int j = 0;j <= 20;j++) {
			if (a[i] & (1<<j)) {
				ans[j]++;
			}
			if (ans[j] > 1) {
				flag = 0;
			}
		}
		if (!flag) {
            pos += cnt;
            while(k < i) {
                int ok = 1;
                for(int j = 0;j <= 20;j++) {
                    ans[j] -= (a[k] & (1<<j)) ? 1 : 0;
                    if(ans[j] > 1) {
                    	ok = 0;
					}
                }
                k++;
                cnt--;
                if (ok) {
                	break;
				} else {
					pos += cnt;
				}
            }
        }
        cnt++;
    }
    printf("%lld\n",pos + ((1 + cnt) * cnt / 2));
	return 0;
}
