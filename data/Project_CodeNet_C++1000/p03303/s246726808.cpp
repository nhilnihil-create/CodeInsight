#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e4;

char s[sz];

int main()
{
    ll i,j,n,d;
    scanf("%s", s);
    cin >> d;
    ll l=strlen(s);
    for(i=0; i<l; i+=d) {
        printf("%c", s[i]);
    }
    puts("");
}
