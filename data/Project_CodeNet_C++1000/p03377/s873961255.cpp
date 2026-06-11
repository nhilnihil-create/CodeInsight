#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long inputs[200005];
long long oddsum[200005];
long long evensum[200005];

int main(){
   int a,b,x;
   cin >> a >> b >> x;
   if(a+b>=x && a<=x)
   {
       cout << "YES" << endl;
   }
   else cout << "NO" << endl;
}
