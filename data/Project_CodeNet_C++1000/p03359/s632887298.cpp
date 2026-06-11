#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int month, day,t;
    cin >> month>> day;
    t=month-1;
    if(day>=month){
        t=t+1;
    }
    else{
        t=t+0;
    }
    printf("%d",t);
    

    
}
