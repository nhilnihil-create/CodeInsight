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
	
	int a, b, c;
	cin >> a  >> b >> c;
	vector<int> v;
	if(a < b){
		for(int i = 1; i <= b ; i++){
		if(a % i == 0 && b %  i == 0){
			v.push_back(i);
		}
	}
	sort(v.rbegin(),v.rend());
	cout << v[c-1] << endl;
	}
	else{
		for(int i = 1; i <= a ; i++){
		if(a % i == 0 && b %  i == 0){
			v.push_back(i);
		}
	}
	sort(v.rbegin(),v.rend());
	cout << v[c-1] << endl;
	}
	
	
	
	
	
	return 0;
}