#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N,M,fd;
    cin>>N>>M;

    if(N==1 && M==1) fd=1;
    else if(N==1 || M==1) fd=max(N,M)-2;
    else fd=(N-2)*(M-2);
    cout <<fd<< endl;

    return 0;
}
