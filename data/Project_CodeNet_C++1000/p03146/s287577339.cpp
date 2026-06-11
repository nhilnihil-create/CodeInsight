#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int S;
    cin >>S;
    int count=1;
   
    for(;;){
        if(S==4||S==2||S==1){
            cout <<count+3<<endl;
            return 0;
        }
        if(S%2==1){
            S=3*S+1;
            count++;
        }
        else{
            S=S/2;
            count++;
    }
    }
}