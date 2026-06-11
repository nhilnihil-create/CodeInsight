#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int mini,maxi,midi;
	mini=min(a,min(b,c));
	maxi=max(a,max(b,c));
	midi = a+b+c-maxi-mini;
	int count=0;
	while(mini<maxi-1){count++;mini+=2;}
	while(midi<maxi-1){count++;midi+=2;}
	a=max(mini,max(midi,maxi));
	if(mini==maxi && maxi==midi) {cout << count;return 0;}
	else if(abs(a-maxi)+abs(a-midi)+abs(a-mini) == 1) {cout << count+2;return 0;}
	else {cout << count+1;return 0;}
			
	
}
