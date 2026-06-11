#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int A,B,X;
   cin >> A >> B >> X;
   
   if(A+B < X) cout << "NO" <<endl;
   else if(A > X) cout << "NO" <<endl;
   else cout << "YES" << endl;
}