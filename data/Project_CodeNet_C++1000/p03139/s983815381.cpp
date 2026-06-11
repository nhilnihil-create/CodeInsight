#include <bits/stdc++.h>
using namespace std;

int main() {

int n,a,b;
cin >> n >> a >> b;
//int *num=new int[3];

//int num[]={300000,200000,100000,0};
//string *name=new string[N+1];

int beg=min(a,b);

int big=a+b;
big=big-n;
if(big<0)big=0;

cout << beg <<" " <<big << endl;


}
