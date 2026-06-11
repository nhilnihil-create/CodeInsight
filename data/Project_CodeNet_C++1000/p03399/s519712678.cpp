#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int a,b,c,d;
cin >> a>> b>> c>>d;
int e = a+c;
int f = a+d;
int g = b+c;
int h = b+d;
cout << min(min(e,f),min(g,h)) << endl;
return 0;
}