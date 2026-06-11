#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include<string>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+4;
int main(){
    ll x;
    while(cin>>x){
    	if(x&1)
    		printf("%lld\n",2*x);
    	else
    		printf("%lld\n",x);
	}
}