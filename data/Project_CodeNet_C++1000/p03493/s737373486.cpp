#include<bits/stdc++.h>
int ctoi(char c) {
 switch (c) {
 case '0': return 0;
 case '1': return 1;
 case '2': return 2;
 case '3': return 3;
 case '4': return 4;
 case '5': return 5;
 case '6': return 6;
 case '7': return 7;
 case '8': return 8;
 case '9': return 9;
 default: return 0;
 }
}

#define ll long long
using namespace std;
int main(){
	string a,b,c;
   cin>>a;
   int q= ctoi(a[0])+ctoi(a[1])+ctoi(a[2]);
   cout<<q;
 return 0;
}
