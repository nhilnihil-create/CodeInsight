#include <iostream>
using namespace std;
int main(void){
    int s,cnt=1;
    cin >> s;
    while(s!=1 && s!=2 && s!=4){
        if(s%2==0) s/=2;
        else s=s*3+1;
        cnt++;
    }
    cout << cnt+3;
}