#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin >> n >> m;
    int start = 1900*m+100*(n-m);
    int x = pow(2,m);
    cout << start * x << endl;

    return 0;
}