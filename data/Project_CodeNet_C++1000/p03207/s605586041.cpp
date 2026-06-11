#include<bits/stdc++.h>
using namespace std;
int main() {
string s,t;
int a,b,c,i;
vector<int> v;
cin>>b;
for(i=0;i<b;i++){cin>>c;v.push_back(c);}
sort(v.begin(),v.end());
a=0;
for(i=0;i<b-1;i++){a=a+v[i];}
a = a+(v[b-1]/2);
cout<<a<<endl;
}