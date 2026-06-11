#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int a, b, c;
int ans;

int main(){
	scanf("%d %d %d", &a, &b, &c);
	// stage 1: tasty poison + tasty antidote
	int step = min(b, c);
	b -= step;
	c -= step;
	ans += 2 * step;
	// stage 2: tasty poison + bad antidote
	step = min(a, c);
	a -= step;
	c -= step;
	ans += step;
	// stage 3: maybe sneak in one tasty poison?
	ans += min(1, c);
	// stage 4: eat all tasty antidotes
	ans += b;
	printf("%d\n", ans);
	return 0;
}