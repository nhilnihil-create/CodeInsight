#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int a = S.at(0)-'0';
    int b = S.at(1)-'0';
    int c = S.at(2)-'0';
    int d = S.at(3)-'0';
    if (a+b+c+d==7) printf("%d%c%d%c%d%c%d=7", a,'+',b,'+',c,'+',d);
    else if (a+b+c-d==7) printf("%d%c%d%c%d%c%d=7", a,'+',b,'+',c,'-',d);
    else if (a+b-c+d==7) printf("%d%c%d%c%d%c%d=7", a,'+',b,'-',c,'+',d);
    else if (a+b-c-d==7) printf("%d%c%d%c%d%c%d=7", a,'+',b,'-',c,'-',d);
    else if (a-b+c+d==7) printf("%d%c%d%c%d%c%d=7", a,'-',b,'+',c,'+',d);
    else if (a-b+c-d==7) printf("%d%c%d%c%d%c%d=7", a,'-',b,'+',c,'-',d);
    else if (a-b-c+d==7) printf("%d%c%d%c%d%c%d=7", a,'-',b,'-',c,'+',d);
    else if (a-b-c-d==7) printf("%d%c%d%c%d%c%d=7", a,'-',b,'-',c,'-',d);
}