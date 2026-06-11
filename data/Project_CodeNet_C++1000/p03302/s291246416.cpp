#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define re return
#define fi first
#define se second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
int main() {
	int a,b;
	cin>>a>>b;
	if(a+b==15)cout<<'+'<<endl;
    if(a*b==15)cout<<'*'<<endl;
    if(a*b!=15 && a+b!=15)cout<<'x'<<endl;
    return 0;
}
