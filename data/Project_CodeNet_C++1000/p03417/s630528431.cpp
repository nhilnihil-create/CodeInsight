#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m;
    cin >> n >> m;
    if(n>2 && m>2)cout << (n-2)*(m-2) << endl;
    else if(n==1 && m==1)cout << 1 << endl;
    else if(min(n,m)==1 && max(n,m)>1)cout << max(n,m)-2 << endl;
    else cout << 0 << endl;
}