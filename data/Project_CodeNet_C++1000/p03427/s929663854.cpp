#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{	
	string s;
	cin >> s;
	int n = s.size();
	int maxsum = 0,sum=0;
	for(int i=0;i<n;i++){
		maxsum = max(maxsum,sum+s[i]-49+(n-i-1)*9);
		sum += s[i]-48;
	}
	maxsum = max(maxsum,sum);
	cout << maxsum;
    return 0;
}