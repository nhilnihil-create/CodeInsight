#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n;
	cin >> n;
	int time = 0, currX = 0, currY = 0;
	
	for(int i = 0; i < n; i++) {
		int t, destX, destY;
		cin >> t >> destX >> destY;
		
		int distance = abs(currX - destX) + abs(currY - destY);
		
		if((t-time-distance)%2 != 0) {
				puts("No");
				return 0;
		}
		
		if(distance > t-time) {
			puts("No");
			return 0;
		}
		
		time = t;
		currX = destX;
		currY = destY;
	}
	puts("Yes");
}
