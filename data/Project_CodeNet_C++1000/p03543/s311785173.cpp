#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string N;
    cin >> N;
    bool flag=false;
    if(N.at(0)==N.at(1)&&N.at(1)==N.at(2))flag=true;
    else if (N.at(1)==N.at(2)&&N.at(2)==N.at(3))flag=true;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}