#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    double N, S, A, T, x, D, AnsD, AnsP=1;
    cin >> N >> S >> A;
    
    for (int i=1; i<=N; i++)
    {
      	cin >> x;
        if (i==1) 
        {
           T = S-x*0.006;
           D = A-T;
           if (D<0) 
           {
             D = -D;
           }
           AnsD = D;
           continue;
        }
        T = S-x*0.006;
        D = A-T;
        if (D<0) D = -D;
        if (D<AnsD) 
        {
        	AnsD = D;
        	AnsP = i;
        }
    }
  	cout << AnsP << endl;
}