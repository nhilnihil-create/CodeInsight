#include<bits/stdc++.h>

using namespace std;

int main() {

  

  int N;

  

  cin >> N;

  

  if ( N%1000 == 0 )

    

    cout << "Yes" << endl;

  

  if ( (N%1000)%111 == 0 && N%1000 != 0)

    

    cout << "Yes" << endl;

  

  if ( N%1111 != 0 && N%1110 <= 9 )

    

    cout << "Yes" << endl;

  

  if (!( N%1000 == 0 || (N%1000)%111 == 0 ||  (N%1111 != 0 && N%1110 <= 9)  ))

    

    cout << "No" << endl;

  

}

