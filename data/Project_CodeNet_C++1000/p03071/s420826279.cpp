#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int sum=0;
for(int i=1;i<=2;i++){
    if(a>=b){
        sum=sum+a;
        a=a-1;


    }
    else{

        sum=sum+b;
        b=b-1;

    }
}
cout<<sum<<endl;


}
