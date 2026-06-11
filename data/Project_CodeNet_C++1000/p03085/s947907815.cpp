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
    char a;
    cin>>a;
    if(a=='A')cout<<"T";
    if(a=='T')cout<<"A";
    if(a=='G')cout<<"C";
    if(a=='C')cout<<"G";
	return 0;
}
