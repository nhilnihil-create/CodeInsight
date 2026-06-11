#include <bits/stdc++.h>
using namespace std;

//A+B=N;
int N, A, B;

int digitsSum(int x){
    if(x/10==0) return x;
    return digitsSum(x/10) + x%10;
}

int main()
{
    cin>>N;

    int mi = 1000000000;
    for (int A = 1; A <= N-1; A++)
    {
        B = N-A;
        mi = min(mi, digitsSum(A) + digitsSum(B));
    }
    
    
    cout << mi << endl;

    return 0;
}
