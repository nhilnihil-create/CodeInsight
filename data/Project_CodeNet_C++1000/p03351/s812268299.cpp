#include<bits/stdc++.h>

using namespace std;

int main(){
    int a , b ,c, d ;

    cin >> a >> b >> c >> d ;
     if ( abs(a-c)< abs(c-b)){
        cout << " Yes";
     }

   else if ( abs(a-b)<= d && abs( b-c)<=d ) {
        cout<<"Yes";
    }
    else {
        cout<< "No";
    }
    return 0 ;
}
