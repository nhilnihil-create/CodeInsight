#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	string A, B;
    cin >> A >> B;
    int a=A.size(), b=B.size();
    vector<char> X(a);
    for (int i=0; i<a; i++){
    	X[i]=A[i];
    }
    vector<char> Y(b);
    for (int i=0; i<b; i++){
    	Y[i]=B[i];
    }
    sort (X.begin(),X.end());
    sort (Y.begin(),Y.end());
    reverse (Y.begin(),Y.end());
    for (int i=0; i<a; i++){
    	A[i]=X[i];
    }
    for (int i=0; i<b; i++){
    	B[i]=Y[i];
    }
    if (A<B) cout << "Yes" << endl;
    else cout << "No" << endl;
}
