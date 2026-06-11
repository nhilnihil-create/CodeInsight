#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int a,b;
    cin >> a >> b;
    if(b%a==0) cout<< a+b << endl;
    else cout << b-a << endl;
}