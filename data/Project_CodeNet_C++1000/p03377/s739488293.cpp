#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,X;
cin >> A >> B >> X;
bool b = true;
if(A > X) b = false;
else if (A + B < X)b = false;

if(b) cout << "YES" <<endl;
else cout << "NO" << endl;

}

