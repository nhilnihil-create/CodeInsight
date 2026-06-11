//                     بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
//                   لآ اِلَهَ اِلّا اللّهُ مُحَمَّدٌ رَسُوُل اللّهِ
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	int a;
	cin >> a;
	
	int ara[a];
	for(int i  = 0 ;i < a; i++) cin >> ara[i];
	sort(ara,ara+a);
	cout << ara[a-1]- ara[0] << endl;
	
	
	
	return 0;
}