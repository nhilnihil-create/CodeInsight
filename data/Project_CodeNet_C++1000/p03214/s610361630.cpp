#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[110];
int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
	}
	double ave = sum*1.0/n;
	int idx;
	double minn = 1000;
	for(int i = 1;i <= n;i++){
        if(abs(a[i]-ave)<minn){
            minn = abs(a[i]-ave);
            idx = i;
        }

	}
	printf("%d",idx-1);
	return 0;
}
