#include <iostream>
using namespace std;
int main(void){
    int a[5],m=1000,i,j;
    for(i=0;i<5;i++) cin >> a[i];
    for(i=0;i<5;i++){
        int tmp=a[i];
        for(j=0;j<5;j++){
            if(i!=j){
                if(a[j]%10==0) tmp+=a[j];
                else tmp+=(a[j]+10-a[j]%10);
            }
        }
        m = min(m,tmp);
    }
    cout << m;
}