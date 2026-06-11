#include <bits/stdc++.h>
using namespace std;


int main(){


    int a, b, k, i;

 
    cin >> a >> b >> k;


    for( i = 0 ; i < k ; i = i + 1 ){

         if( i % 2 == 0 ){

             if( a % 2 != 0 ) a -= 1;

             b += a / 2;

             a = a / 2;

             }

         else{

               if( b % 2 != 0 ) b -= 1;  

               a += b / 2;

               b = b / 2;

               }

         }


    cout << a << " " << b << endl;


    return 0;


    }