#include <iostream>
using namespace std;

int main() {
    int a,b;cin>>a>>b;
    int s = b-a;
    int t = (s-1) * s /2;
    cout<<t - a<<endl;
	return 0;
}