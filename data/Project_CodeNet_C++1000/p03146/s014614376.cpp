#include <bits/stdc++.h>
using namespace std;

int main() {
	int a;
	cin >> a;
	set <int> A;
	while (A.count(a)==0){
	    A.insert(a);
	    if (a%2==1){
	        a=3*a+1;
	    }
	    else a/=2;
	}
	cout << A.size()+1 << endl;
}
