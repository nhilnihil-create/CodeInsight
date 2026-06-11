#include <bits/stdc++.h>
using namespace std;
int main()
{
int N,M,X;
cin >> N >> M >> X;
vector<int> A(M);
for(int i=0; i<M; i++)
{
    cin >> A.at(i);
}
int chkA=0,chkB=0;
for(int i=0; i<M; i++)
{
    if(A.at(i)<X)
    {
        chkA++;
    }
    else
    {
        chkB++;
    }
}
cout << min(chkA,chkB) << endl;
}