#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    cout << (n-1)/(k-1)+((n-1)%(k-1)>0) << endl;
}