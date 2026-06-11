#include <bits/stdc++.h>
#define ll long long
#define MAX 5005
using namespace std;

int n, a[MAX];
ll f[MAX], A, B;

int main()
{
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    a[n+1] = n+1;
    n++;
    for(int i = 1; i <= n; i++){
        ll s = 0;
        for(int j = i-1; j >= 0; j--){
            if(a[i] > a[j]){
                f[i] = min(f[i], f[j]+s);
                s += B;
            }
            else s += A;
        }
    }
    cout << f[n] << endl;

	return 0;
}