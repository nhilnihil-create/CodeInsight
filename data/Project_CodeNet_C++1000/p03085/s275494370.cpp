#include<bits/stdc++.h>
using namespace std;
const int n = 1e5+3;
char x[n];
int main(void){
char b;
cin>>b;
pair<char,char>x[2];
x[0]=make_pair('A','T');
x[1]=make_pair('C','G');
for(int i=0;i<2;i++)
{
    if(x[i].first==b)
        cout<<x[i].second<<endl;
    else if(x[i].second==b)
        cout<<x[i].first<<endl;
}
return 0;}
