#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <string>
#include <functional>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pci pair<char,int>
#define pdd pair<double,double>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pdi pair<double,int>
#define pdd pair<double,double>
#define mod 1000000007
#define mod1 1000000009
#define mod2 1000000021
#define INF 987564231
#define MAX 2000001
long double PI = 3.141592653589793238462643383279502884197;
using namespace std;

/* 🐣🐥 */
char A[200001], B[200001];
int main() {
	int n, m, t, r, c;
	scanf("%d %d %d %d %d", &n, &m, &t, &r, &c);
	scanf("%s %s", A, B);
	int R = c, L = 0;
	for (int i = 0; i < 2*t; i++){
		if (i % 2){
			if (B[i / 2] == 'L' && R > 1) R--;
		}
		else {
			if (A[i/2] == 'L'){
				if (R == 1 && L){
					L--;
					R++;
				}
			}
			else if(A[i / 2] == 'R'){
				R++;
				if (R == m + 1) return !printf("NO");
			}
		}
	}
	R = c, L = 0;
	for (int i = 0; i < 2 * t; i++){
		if (i % 2){
			if (B[i / 2] == 'R' && R < m) R++;
		}
		else {
			if (A[i / 2] == 'R'){
				if (R == m && L){
					L--;
					R--;
				}
			}
			else if (A[i / 2] == 'L'){
				R--;
				if (R == 0) return !printf("NO");
			}
		}
	}
	//////////////
	R = r, L = 0;
	for (int i = 0; i < 2 * t; i++){
		if (i % 2){
			if (B[i / 2] == 'U' && R > 1) R--;
		}
		else {
			if (A[i / 2] == 'U'){
				if (R == 1 && L){
					L--;
					R++;
				}
			}
			else if (A[i / 2] == 'D'){
				R++;
				if (R == n + 1) return !printf("NO");
			}
		}
	}
	R = r, L = 0;
	for (int i = 0; i < 2 * t; i++){
		if (i % 2){
			if (B[i / 2] == 'D' && R < n) R++;
		}
		else {
			if (A[i / 2] == 'D'){
				if (R == n && L){
					L--;
					R--;
				}
			}
			else if (A[i / 2] == 'U'){
				R--;
				if (R == 0) return !printf("NO");
			}
		}
	}
	printf("YES");

	return 0;
}