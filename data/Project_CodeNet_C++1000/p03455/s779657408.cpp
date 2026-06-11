#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int a,b;
    cin>>a>>b;
    if((a*b)&1)cout<<"Odd";
    else cout<<"Even";
	return 0;
}
