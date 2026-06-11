#include <bits/stdc++.h>
using namespace std;

int n,a;

int main(){
    cin>>n>>a;

    int b = n%500;
    if(a>=b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}