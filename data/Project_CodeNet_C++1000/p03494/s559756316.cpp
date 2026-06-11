#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N,x;
cin>>N;
int cnt = 0;
for(int i = 0;i<N;i++){
cin>>x;
int j = 0;
while(x%2!=1){
x /=2;
j++;}
if(i==0){
cnt=j;}
if(cnt>j){
cnt=j;}
}
cout<<cnt;
}
