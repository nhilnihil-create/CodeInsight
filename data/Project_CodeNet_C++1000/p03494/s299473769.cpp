#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
   	int N, count=0;
  	cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++){
    	cin >> A[i];
    }
    bool check = 1;
    while (check){
      	for (int i=0; i<N; i++){
    		if (A[i]%2!=0) {
            	cout << count << endl;
                check = 0;
            	break;
            }
        }
        for  (int i=0; i<N; i++){
        	A[i]/=2;
        }
        count++;
    }
}