#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)


int A,B,C;
int main(){
    string S;
    cin >> S;
    int N = S.length();
    REP(i,N){
        char x = S[i];
        if(x == 'a') A++;
        else if(x == 'b') B++;
        else if(x == 'c') C++;
        else cout << "Error" << endl;
    }

    int diff_ab = abs(A-B);
    int diff_bc = abs(C-B);
    int diff_ca = abs(A-C);

    if(diff_ab > 1 || diff_bc > 1 || diff_ca > 1) {
        cout << "NO" << endl;
        return 0;
    }else{
        cout << "YES" << endl;
        return 0;
    }
    return 0;
}
