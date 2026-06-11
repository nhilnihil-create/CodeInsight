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
    char a,b;
    cin>>a>>b;
    if(a-'A'<b-'A')cout<<"<";
    else if(a==b)cout<<"=";
    else cout<<">";
	return 0;
}
