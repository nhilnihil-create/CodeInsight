#include <bits/stdc++.h>
using namespace std;
int op[8][3]={
    1,1,1,
    1,1,-1,
    1,-1,1,
    1,-1,-1,
    -1,1,1,
    -1,1,-1,
    -1,-1,1,
    -1,-1,-1
};
string s;
int a[4];
int main() {
   cin >> s;
   for (int i=0; i<4; i++) a[i]=s[i]-48;
   int i=0;
   while (true) {
       if (a[0]+op[i][0]*a[1]+op[i][1]*a[2]+op[i][2]*a[3]==7) {
           cout << a[0] << 
           (op[i][0]==-1 ? '-' : '+') << a[1] <<
           (op[i][1]==-1 ? '-' : '+') << a[2] <<
           (op[i][2]==-1 ? '-' : '+') << a[3] <<
           "=7";
           
           return 0;
       }
       i++;
   }
}