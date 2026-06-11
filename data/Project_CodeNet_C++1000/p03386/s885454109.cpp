#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;



int main(){
	int a, b, k;
	cin >> a >> b >> k;

	if (b-a < 2*k){
		for (int i = a; i <= b; i++){
			cout << i << endl;
		}
	}else{
		for (int i = a; i < a + k; i++){
			cout << i << endl;
		}
		for (int i = b-k+1; i <= b; i++){
			cout << i << endl;
		}
	}
	return  0;
}