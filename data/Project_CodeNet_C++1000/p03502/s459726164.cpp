#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m = n;
    int d,sum=0;
    for(int i=0;i<=8;i++){
        /*if(n<pow(10,i)){
            break;
        }*/
        d = n%10;
        sum += d;
        n = n/10;
    }
    
    if(m%sum==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}