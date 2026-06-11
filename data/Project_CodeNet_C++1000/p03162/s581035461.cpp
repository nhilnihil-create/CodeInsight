#include<bits/stdc++.h>
using namespace std;
int a[100000+5];
int b[100000+5];
int c[100000+5];

int main(int argc, char const *argv[])
{
	int N;
	while(cin >> N) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for(int i=1; i<=N; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		for(int i=2; i<=N; i++){
			int tempa = a[i - 1];
			int tempb = b[i - 1];
			int tempc = c[i - 1];
			a[i] = a[i] + max(tempb, tempc);
			b[i] = b[i] + max(tempa, tempc);
			c[i] = c[i] + max(tempa, tempb);
		}
	    cout << max(a[N], max(b[N], c[N])) << endl;
    }
	return 0;
}