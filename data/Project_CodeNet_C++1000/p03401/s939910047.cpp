#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;

int main()
{
	int n;
	cin>>n;
	int *A = new int[n+2];
	int *left = new int[n+2];
	int *right = new int[n+2];
	A[0] = 0;
	A[n+1] = 0;
	for(int i = 1; i <= n; i++){
		cin>>A[i];
	}
	left[0] = 0;
	for(int i = 1; i <= n+1; i++){
		left[i] = left[i-1] + abs(A[i-1] - A[i]);
	}
	right[n+1] = 0;
	for(int i = n; i != 0; i--){
		right[i] = right[i+1] + abs(A[i] - A[i+1]);
	}
	for(int i = 1; i <= n; i++){
		cout<< left[i-1] + right[i+1] + abs( A[i-1] - A[i+1])<<endl;
	}
	return 0;
}

