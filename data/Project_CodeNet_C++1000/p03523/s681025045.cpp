#include <iostream>
#include <stdio.h>
#include<string>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	string s;

	cin >> s;

	if (s == "AKIHABARA") { printf("YES");return 0; }
	if (s == "KIHABARA") { printf("YES");return 0; }

	if (s == "AKIHBARA") { printf("YES");return 0; }
	if (s == "AKIHABRA") { printf("YES");return 0; }
	if (s == "AKIHABAR") { printf("YES");return 0; }
	if (s == "KIHBARA") { printf("YES");return 0; }
	if (s == "KIHABRA") { printf("YES");return 0; }
	if (s == "KIHABAR") { printf("YES");return 0; }
	if (s == "AKIHBRA") { printf("YES");return 0; }
	if (s == "AKIHBAR") { printf("YES");return 0; }
	if (s == "AKIHABR") { printf("YES");return 0; }
	if (s == "KIHBRA") { printf("YES");return 0; }
	if (s == "KIHBAR") { printf("YES");return 0; }
	if (s == "KIHBRA") { printf("YES");return 0; }
	if (s == "KIHABR") { printf("YES");return 0; }
	if (s == "AKIHBR") { printf("YES");return 0; }
	if (s == "KIHBR") { printf("YES");return 0; }
	cout << "NO";
}
