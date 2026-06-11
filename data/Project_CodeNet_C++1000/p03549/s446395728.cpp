#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    int ac,tle;
    ac=n-m;
    tle=m;
    cout << pow(2,tle)*(100*ac+1900*tle) << endl;
}