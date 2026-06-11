#include <bits/stdc++.h>
using namespace std;


int main(){


    int n, t, mat, mit, abt, i;

    int ma = -10000000;

    int mi = 10000000;


    vector<int> a;

 
    cin >> n;


    for( i = 1 ; i < n + 1 ; i = i + 1 ){

         cin >> t;

         a.push_back(t);

         if( t > ma ){

             ma = t;

             mat = i;

             }

         else if( t < mi ){

                  mi = t;

                  mit = i;

                  }

         }


    if( mi >= 0 ){

        cout << n - 1 << endl;


        for( i = 1 ; i < n ; i = i + 1 ){

             cout << i << " " << i + 1 << endl;

             }

        }
        

    else if( ma <= 0 ){

             cout << n - 1 << endl;


             for( i = n ; 1 < i ; i = i - 1 ){

                  cout << i << " " << i - 1 << endl;

                  }

             }

    
    else{

           if( ma > -mi ){

               cout << 2 * n - 1 << endl;


               for( i = 1 ; i < n + 1 ; i = i + 1 ){

                    cout << mat << " " << i << endl;

                    }
 
  
               for( i = 1 ; i < n ; i = i + 1 ){

                    cout << i << " " << i + 1 << endl;

                    }

               }

           else{ 

                 cout << 2 * n - 1 << endl;


                 for( i = 1 ; i < n + 1 ; i = i + 1 ){

                      cout << mit << " " << i << endl;

                      }


                 for( i = n ; 1 < i ; i = i - 1 ){

                      cout << i << " " << i - 1 << endl;

                      }

                 }

            } 


    return 0;


    }