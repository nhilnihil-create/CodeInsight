#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,a,b,i=0;
    string result="nothing";
    cin>>n>>a>>b;
    while(result=="nothing"){
        i++;
        if(b!=a+1){
            a++;
        }else{
            a--;
            if(a==0)result="Borys";
        }
        if(a!=b-1){
            b--;
        }else{
            b++;
            if(b==n+1)result="Alice";
        }
        if(i>=2*n)result="DRAW";
    }
    cout<<result<<endl;
}