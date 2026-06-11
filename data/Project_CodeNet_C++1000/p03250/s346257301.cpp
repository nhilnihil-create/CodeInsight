#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int a,b,c;
    cin >>a>>b>>c;
    if(a<b)swap(a,b);
    if(a<c)swap(a,c);
    cout << 10*a+b+c << endl;
    return 0;
}
