#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B,C,D;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    int sum = 0;
    if(A<B){
      sum = sum+A;
    }
    else{
      sum = sum+B;
    }
    if(C<D){
      sum = sum+C;
    }
    else{
      sum = sum+D;
    }
    cout << sum << endl;
}
      