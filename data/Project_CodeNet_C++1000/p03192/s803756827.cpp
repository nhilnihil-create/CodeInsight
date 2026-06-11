#include <bits/stdc++.h>
using namespace std;
int main() {
int a;
int cnt=0;cin>>a;
if(a/1000==2)cnt++;
if(a%1000/100==2)cnt++;
if(a%100/10==2)cnt++;
if(a%10==2)cnt++;cout<<cnt<<endl;
}