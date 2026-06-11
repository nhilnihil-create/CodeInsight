#include<iostream>
#include<string>
#include<set>
#include <iterator>
using namespace std;
template<typename T>
void print(T value)
{
	cout << value << endl;
}

void init() 
{
	
}
int n, m;
int result;
char symbol[] = {'+', '*', 'x'};
int main() 
{
	cin >> n >> m;
	if(n*m == 15)
	{
		result = 1;
	}
	else if(n+m == 15)
	{
		result = 0;
	}
	else 
	{
		result = 2;
	}
	print(symbol[result]);
	return 0;
}