#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
using namespace std;
typedef long long ll;


int main(int argc, char *args[]) {
	int a, b;
	cin >> a >> b;
	if (a + b == 15)cout << "+" << endl;
	else if (a*b == 15)cout << "*" << endl;
	else cout << "x" << endl;
	
}
