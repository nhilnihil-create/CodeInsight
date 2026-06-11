#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int a=0,b=0,c=0;
    char ch;
    while(cin>>ch){
        if(ch=='a')a++;
        if(ch=='b')b++;
        if(ch=='c')c++;
    }
    cout<<((fabs(a-b)<=1&&fabs(b-c)<=1&&fabs(c-a)<=1)?"YES":"NO")<<endl;
}