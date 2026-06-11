#include <bits/stdc++.h>
using namespace std;

int N,A;

int main(){
    cin>>N>>A;

    int a = N%500;

    if(A>=a) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
