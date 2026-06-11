#include<iostream>
using namespace std;
int main(){
int n;
cin >>n;
int sum=0;
int total=0;
if(n<105){
    cout << 0 <<endl;
}
else if(n==105){
    cout << 1 <<endl;
}
else if(n>105){
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(i%j==0){
               sum++;
           }
       }
       if(sum==8){
           total++;
       }
        sum=0;
            i++;
    }
    cout << total <<endl;
}
 
}