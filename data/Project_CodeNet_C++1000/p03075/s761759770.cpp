#include <bits/stdc++.h>
using namespace std;


 int main (){
     int a,b,c,d,e,k;
     cin >> a >> b >> c >> d >> e >> k;
     bool t=false;
     if(b-a>k){t=true;}
     if(c-b>k){t=true;}
     if(d-c>k){t=true;}
     if(e-d>k){t=true;}
     if(c-a>k){t=true;}
     if(d-b>k){t=true;}
     if(e-c>k){t=true;}
     if(d-a>k){t=true;}
     if(e-b>k){t=true;}
     if(e-a>k){t=true;}
     if(t==true){cout << ":("<<endl;}
     else {cout << "Yay!"<<endl;}
 }