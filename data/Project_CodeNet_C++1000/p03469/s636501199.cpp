#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
char arr[10];
for(int i=0;i<10;i++){
cin>>arr[i];
}
arr[3]='8';
for(int i=0;i<10;i++)
{
cout<<arr[i];
}
return 0;  
}