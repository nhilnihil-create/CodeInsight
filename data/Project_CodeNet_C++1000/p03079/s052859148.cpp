#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
//#include <chrono>
//#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 100005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int a[N];

int main() {
	//mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
	int n = 3;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a + 1 , a + n + 1);
	if(a[1] == a[2] && a[2] == a[3]){
        cout<<"Yes"<<endl;
	}
	else{
        cout<<"No"<<endl;
	}
	return 0;
}
