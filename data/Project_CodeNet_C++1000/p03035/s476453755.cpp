#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int A, B; cin >> A >> B;
	cout << (A >= 13 ? B : (A <= 5 ? 0 : B / 2)) << endl;
}