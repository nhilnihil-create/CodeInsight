#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
   int n;cin>>n;
   int a,b;cin>>a>>b;
   if((abs(a-b)-1)%2!=0)cout<<"Alice"<<endl;
   else cout<<"Borys"<<endl;
}