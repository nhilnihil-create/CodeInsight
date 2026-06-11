#include <bits/stdc++.h>
using namespace std;

int main(){
int A;
vector <char> op(3);
vector <int> vec(4);
cin>>A;
for(int i=0;i<4;i++){
vec.at(3-i)=A%10;
A/=10;
}


for(int tmp=0;tmp<(1<<3);tmp++){
int sum=vec.at(0);
 bitset<3> s(tmp);
for(int i=0;i<3;i++){
if(s.test(i)){
op.at(i)='+';
sum+=vec.at(i+1);}
else{
op.at(i)='-';
sum-=vec.at(i+1);}
}
if(sum==7){
cout<<vec.at(0)<<op.at(0)<<vec.at(1)<<op.at(1)<<vec.at(2)<<op.at(2)<<vec.at(3)<<"=7"<<endl;
break;}
}
}





