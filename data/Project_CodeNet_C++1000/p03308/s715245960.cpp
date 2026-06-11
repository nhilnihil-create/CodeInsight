#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    int N,A;

    cin >> N;

    int max = 0;
    int min = 1000000000;
    rep(i,N){
        cin >>A;
        if(max < A) max =A;
        if(min > A) min =A;
    }

    cout << (max-min) << endl;
}

    
