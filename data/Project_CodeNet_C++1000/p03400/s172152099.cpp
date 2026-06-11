
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int N, D, X;
   int A[N + 1];
   cin >> N >> D >> X;
   int temp;
   int contador = 0;
   for(int i = 1; i <= N; ++i){
    cin >> temp;
    contador += ceil((float)D/temp);
   }
   
   cout << contador + X << endl;


}
