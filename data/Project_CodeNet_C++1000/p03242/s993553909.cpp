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
    int n;
    while(cin>>n){
    	int dep=1;
    	while(dep*10<=n)
    		dep*=10;
    	while(n){
    		int t=n/dep;
    		if(t==9)
    			t=1;
    		else if(t==1)
    			t=9;
    		cout<<t;
    		n%=dep;
    		dep/=10;
		}
		cout<<endl;
	}
}