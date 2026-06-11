#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e3+7;
const ll mod = 1e9+7;
int main()
{
    for(int i=0;i<3;i++){
        char c=getchar();
        if(c=='1')putchar('9');
        else if(c=='9')putchar('1');
        else putchar(c);
    }
}
