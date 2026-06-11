#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	cin >> n;
	int ans = 0;
	if (n.at(0) == '1')ans++;
	if (n.at(1)== '1')ans++;
	if (n.at(2) == '1')ans++;
	
	
	cout << ans << endl;


}
