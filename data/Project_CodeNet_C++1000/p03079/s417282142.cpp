#include <bits/stdc++.h>
using namespace std;

int main() {

int n1,n2,n3;
cin >> n1 >> n2 >> n3;
//int *num=new int[3];

//int num[]={300000,200000,100000,0};
//string *name=new string[N+1];

int ma=max(max(n1,n2),n3);
int mi=min(min(n1,n2),n3);
if(ma==mi)
cout << "Yes" << endl;
else
cout << "No" << endl;


}
