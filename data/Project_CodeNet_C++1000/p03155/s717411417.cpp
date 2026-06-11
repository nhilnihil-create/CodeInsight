#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define X first
#define Y second
#define ws asdnasdkns
#define LL long long
#define PI acos(-1.0)
const LL mod = 1000 * 1000 * 1000 + 7;
const LL MAX = 200005;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   	//freopen("In.txt" , "r" , stdin);
	srand(time(NULL));
	int n , h , w;
	cin >> n >> h >> w;
	cout << (n + 1 - h) * (n + 1 - w);
}