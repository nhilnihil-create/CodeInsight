#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	int n, m, x,a[100],i=0,lcnt=0,rcnt=0;
	cin >> n >> m >> x;
	for (int i = 0;i < m;i++)cin >> a[i];
	while (a[i] < x) {
		lcnt++;
		i++;
	}
	rcnt = m - lcnt;
	cout << min(lcnt, rcnt) << endl;
	
}