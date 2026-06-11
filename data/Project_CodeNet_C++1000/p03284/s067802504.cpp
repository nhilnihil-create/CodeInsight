#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <math.h>
#include <vector>
#include <cctype>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;
	if(a%b != 0){
		cout << 1;
	}else{
		cout << 0;
	}
}
