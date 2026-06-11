#include<bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    int cnt=0;
    for (int i=N; i>=1; i/=10) {
        cnt+=i%10;
    }
    if (N%cnt==0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
        
    
