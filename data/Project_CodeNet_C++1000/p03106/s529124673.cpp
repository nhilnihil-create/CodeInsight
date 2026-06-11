#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;


int main()
{
	int A,B,K;
	cin>>A>>B>>K;
	for(int i = min(A,B); i >= 1; i--){
		if( A % i == 0 && B % i == 0) K--;
		if( K == 0){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
