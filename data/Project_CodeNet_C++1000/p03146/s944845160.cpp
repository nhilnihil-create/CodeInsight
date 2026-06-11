#include <bits/stdc++.h>
using namespace std;


int main() {
	int s,tmp,count=1;
	cin >> s;
	
	map<int, int> score;
	score[s] = 1;
	tmp = s;
	while (true)
	{
		if (tmp%2==0)
		{
			tmp /= 2;
		}
		else {
			tmp = 3 * tmp + 1;
		}
		count++;
		if (score[tmp])
		{
			break;
		}else{
			score[tmp] = 1;
		}
	}
	cout << count << endl;
}
