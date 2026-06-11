#include <stdio.h>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

bitset<16080> p[2];
char S[8080];

int main()
{
	scanf ("%s",S);
	int d = -1, l = 0, x, s[2] = {0,};
	p[1][0] = 1;
	for (int i=0;;i++){
		if (S[i] == 'T' || S[i] == 0){
			if (d == -1){
				d = 0;
				p[0][2*l] = 1;
			}
			else p[d] |= p[d] << (2*l);
			s[d] += l;
			l = 0;
			d = !d;

			if (S[i] == 0) break;
		}
		else l++;
	}

	int X,Y; scanf ("%d %d",&X,&Y);
	X += s[0], Y += s[1];
	if (0 <= X && p[0][X] && 0 <= Y && p[1][Y]) puts("Yes");
	else puts("No");

	return 0;
}