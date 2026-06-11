#include <iostream>
using namespace std;

int main(){
    int a,b,x[5],num,count=0;
    cin>>a>>b;
    
    for(int i=a;i<=b;i++){
        num=i;
        for(int j=0;j<5;j++){
            x[j]=num%10;
            num/=10;
        }
        if(x[0]==x[4]&&x[1]==x[3])
            count++;
    }
    cout<<count<<endl;
}
