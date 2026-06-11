#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int A,B,C,X,ANS=0;
	int i=0,j=0,k=0;
	cin >> A >> B >> C >> X;
	while(i<=A && j<=B && k<=C){
		//cout << i << ":" << j << ":" << k << endl;
		//cout << i*500+j*100+k*50 << endl;
		if(X==i*500+j*100+k*50)ANS++;
		if(k<C){
			k++;
		}
		else if(k==C&&j<B){
			j++;
			k=0;
		}
		else if(k==C&&j==B){
			i++;
			j=0;
			k=0;
		}
	}
	cout << ANS << endl;
}