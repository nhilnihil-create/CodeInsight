#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;
string check(char s[], char t[], int s_size, int t_size)
{
	int smaller = s_size > t_size ? t_size : s_size;
	for(int i = 0; i < smaller; i++)
		if( s[i] > t[t_size - i - 1] )
			return "No";
		else if( s[i] < t[t_size - 1 - i] )
			return "Yes";
	if( t_size > s_size )
		return "Yes";
	return "No";
}
int main()
{
	string s, t;
	cin >> s >> t;
	char s_arr[ s.size() ], t_arr[ t.size() ];
	
	for(int i = 0; i < s.size(); i++)
		s_arr[i] = s[i];
	sort(s_arr,s_arr+s.size());	
	for(int i = 0; i < t.size(); i++)
		t_arr[i] = t[i];
	sort(t_arr,t_arr+t.size());	
	cout << check(s_arr,t_arr,s.size(),t.size());
}