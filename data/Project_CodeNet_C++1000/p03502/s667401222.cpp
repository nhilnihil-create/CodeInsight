#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int func(int n)
{
	int temp =n ;
	int s=0;
	while(temp>0){
		s += temp%10;
		temp/=10;
	}
	return s;
}

int main()
{	
	int n, s;
	cin >> n;
	s = func(n);
	if(n%s) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}
