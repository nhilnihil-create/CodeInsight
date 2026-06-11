#include <bits/stdc++.h>
using namespace std;

void Yes(bool f){cout<<(f?"Yes":"No")<<endl;}

signed main()
{
    int A,B,C; cin >>A>>B>>C;

    Yes(A==B && B==C);
}
