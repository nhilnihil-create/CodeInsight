#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, s, count=0;
    cin >> X >> Y;
    vector<int> A(5);
    for (int i=X; i<=Y; i++){
            s = i;
    		for (int k=0; k<5; k++){
              		A[k] = s%10;
                    s = (s-s%10)/10;
            }
            if ((A[0]==A[4])&&(A[1]==A[3])) count++;
    }
    cout << count << endl;
              		
}