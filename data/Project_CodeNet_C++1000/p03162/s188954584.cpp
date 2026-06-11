#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	if(n == 0) return 0;
	
	int a, b, c;
	int s1, s2, s3;
	int s1_prev, s2_prev, s3_prev;
	cin >> a >> b >> c;
	s1 = a;
	s2 = b;
	s3 = c;
	for(int i = 1; i < n; i++)
	{
		s1_prev = s1;
		s2_prev = s2;
		s3_prev = s3;
		
		cin >> a >> b >> c;
		
		s1 = max(s2_prev, s3_prev) + a;
		s2 = max(s1_prev, s3_prev) + b;
		s3 = max(s1_prev, s2_prev) + c;
	}
	cout << max(s1, max(s2, s3));
	return 0;
}
