#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
 
int main() {
	int h, w;
	cin >> h>>w;

	string s[55];
	int i,j;
	int cnt = 0;

	for (i = 0; i < h; i++)
	{
		cin >> s[i];
	}
	
	int x[8] = { -1,0,1,-1,1,-1,0,1 };
	int y[8] = { 1,1,1,0,0,-1,-1,-1 };

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (s[i].at(j) == '#')continue;
			for (int k = 0; k < 8; k++)
			{
				int nx = j + x[k];
				int ny = i + y[k];
				//cout << nx << ":" << ny << endl;
				if (nx < 0 || w<= nx)continue;
				if (ny < 0 || h<= ny)continue;
				//cout << nx << ":" << ny<<endl;
				if (s[ny].at(nx) == '#')cnt++;
			}
			//cout << endl;
			s[i].at(j) = char(cnt+'0');
			cnt = 0;
		}
	}
	for (i = 0; i < h; i++)
	{
		
		cout<<s[i] << endl;
	}
}
	


/**/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main(void) {
	return 0;
}
*/