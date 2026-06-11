#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
string n;
cin>>n;
int a=0;
int b=0;
int s=n.size();
for(int i=0; i<s; i++){
a+=n.at(i)-'0';}
if(a==9*(s-1)+n.at(0)-'0'){
cout<<a<<endl;}
else{
cout<<9*(s-1)+n.at(0)-'0'-1<<endl;}
}
