#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int cans(bool f){
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}


int main(){
    int a[3],b[3],c[3];
    rep(i,3) {
	cin >> a[i] >> b[i] >> c[i];
    }


    bool f = false;
    for(int i=1; i<3; i++) {
	for(int h1=-100; h1<=100; h1++) {
	    for(int h2=-100; h2<=100; h2++) {
		if(a[0] == b[0] + h1 && a[0] == c[0] + h2 && a[1] == b[1] + h1 && a[1] == c[1] + h2 && a[2] == b[2] + h1 && a[2] == c[2] + h2) f = true;
	    }
	}
    }
    cans(f);
    
    return 0;
}

