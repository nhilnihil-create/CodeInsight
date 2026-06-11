#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	
	string s;
	cin>>s;
	
	int k = 0;
	int n = s.size();
	for(int i = 0; i < n-1; i++)
	{
		if(i == -1)
		{
			i++;
		}
		if(s[i] != s[i+1])
		{
			k+=2;
			s.erase(i,2);
			i-=2;
			n-=2;
		}
	}
	cout<<k;
	return 0;
}