#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int A,B,C,X,Y;
    int min_c=100000000000;
    cin>>A>>B>>C>>X>>Y;

        for(int i=0;i<=max(X,Y);++i){
            int sum=2*C*i+A*max(0,X-i)+B*max(0,Y-i);
            min_c=min(min_c,sum);
        }
     cout<<min_c;
    

}