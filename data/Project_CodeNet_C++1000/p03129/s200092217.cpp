#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;

    cin >> N >>K;
    
    if(K == 1) cout << "YES" << endl;
    else if((N-1)/(K-1) >=2) cout << "YES" << endl;
    else cout << "NO" << endl;

}