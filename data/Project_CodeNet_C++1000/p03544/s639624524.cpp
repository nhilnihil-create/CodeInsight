#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int n;
    cin>>n;
    vector<long long>l(87);
    l[0]=2;
    l[1]=1;
    for(int i=2;i<87;i++)l[i]=l[i-1]+l[i-2];
    cout<<l[n];
	return 0;
}
