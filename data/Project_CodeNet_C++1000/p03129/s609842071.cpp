#include<iostream>
#include<string>

using namespace std;

int main() {
	int n,k;
	cin >> n>>k;
	if (n % 2 == 1)n++;
	if (n / 2 >= k)cout << "YES";
	else cout << "NO";

}