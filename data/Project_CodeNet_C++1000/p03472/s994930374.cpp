#include <bits/stdc++.h>
using namespace std;
int main(){
long long counter1,counter2,a,b;
counter1=0;
counter2=0;
long long N,H;
cin>>N>>H;
if(N==1){
cin>>a>>b;
counter2=1;
H-=b;
if(H%a>0){
cout<<counter2+H/a+1<<endl;}
else{
cout<<counter2+H/a<<endl;}}
else{
priority_queue<long long>aa;
priority_queue<long long>bb;
for(long long i=0;i<N;i++){
cin>>a>>b;
aa.push(a);
bb.push(b);}
counter1=aa.top();
while(H>0&&bb.size()>0){
if(bb.top()<=counter1){
break;
}
else
H=H-bb.top();
bb.pop();
counter2++;
}
if(H>0&&H%counter1>0){
cout<<counter2+(H/counter1)+1<<endl;}
else if(H>0&&H%counter1==0){
cout<<counter2+(H/counter1)<<endl;}
else{
cout<<counter2<<endl;}}}
