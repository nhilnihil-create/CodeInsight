#include <bits/stdc++.h>
using namespace std;

int main() {


//int n,a,b;
int *num=new int[4];
cin >> num[0] >> num[1] >> num[2] >> num[3];
//int *num=new int[3];

//int num[]={300000,200000,100000,0};
//string *name=new string[N+1];


sort(num,num+4);
if(num[0]==1 && num[1]==4 && num[2]==7 && num[3]== 9)
cout << "YES" << endl;
else
cout << "NO" << endl;



}
