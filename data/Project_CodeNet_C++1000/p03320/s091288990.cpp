    #include <bits/stdc++.h>
    using namespace std;
    int k, y;
    long long x;
    const long long maxi[] = {9, 99, 1999, 29999, 399999, 4999999, 59999999, 699999999LL, 7999999999LL, 89999999999LL, 999999999999LL, 9999999999999LL, 109999999999999LL, 1199999999999999LL, 100000000000000000LL};
    long long ten[25];
    int main()
    {
    #ifdef _noname
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    	scanf("%d", &k);
    	ten[0] = 1;
    	for (int i = 1; i <= 16; i++) ten[i] = ten[i - 1] * 10;
    	x = 0;
    	for (int i = 1; i <= k; i++)
    	{
    		y = 0;
    		while (x >= maxi[y]) y++;
    		x += ten[y];
    		printf("%lld\n", x);
    	}
    	return 0;
    }