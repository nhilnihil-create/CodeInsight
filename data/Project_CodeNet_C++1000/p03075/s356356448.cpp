#include <bits/stdc++.h>
using namespace std;

int dist(int i, int j)
{
 	return abs(i - j); 
}

bool good = true;
int a[6],k;
int main()
{
	for(int i = 0; i < 5; i++)
      	cin >> a[i];
  	cin >> k;
  	
  	for(int i = 0; i < 5 && good; i++)
      	for(int j = 0; j < 5 && good; j++)
          	good = (good && dist(a[i], a[j]) <= k);
  	cout << (good ? "Yay!" : ":(") << endl;
  	return 0;
}