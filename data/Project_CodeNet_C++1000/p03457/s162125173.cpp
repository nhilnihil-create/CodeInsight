#include<bits/stdc++.h>
using namespace std;

int main() {
  	int num, step, dist;
  	scanf("%d", &num);
  	int t, x, y, pt=0, px=0, py=0;
  	for(int i = 0; i < num; i++) {
    	scanf("%d %d %d", &t, &x, &y);
      	step = t - pt;
      	dist = abs(x - px) + abs(y - py);
      	if (dist > step) {
        	cout << "No" << endl;
          	return 0;
        }
      	if (((step - dist) % 2) != 0) {
          	cout << "No" << endl;
          	return 0;
        }
      	pt = t;
      	px = x;
      	py = y;
    }
  	cout << "Yes" << endl;
	return 0;  
}