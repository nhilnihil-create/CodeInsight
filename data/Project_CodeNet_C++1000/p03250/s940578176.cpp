#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int A,B,C,max,n;

    cin>>A>>B>>C;

    max=A;
    if(max<B)max=B;
    if(max<C)max=C;
    n=10*max+A+B+C-max;

    cout<<n<<endl;

    return 0;
}