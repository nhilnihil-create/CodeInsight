#include <iostream>
using namespace std;
typedef long long int LLI;

void solution(string s)
{
	cout << "2018/01/" << s[s.size()-2] << s[s.size()-1];
}
int main()
{
	string s;
	cin >> s;
	solution(s);
}