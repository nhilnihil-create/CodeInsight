#include <iostream>
using namespace std;
int main(){
    int a,b;
    int count =0;
    cin >> a >> b;
    for(int i = a;i<=b;i++){
        int cp = i;
        int ue = 0;
        ue += cp/10000;
        cp %= 10000;
        ue += (cp/1000)*10;
        cp %= 1000;
        cp %= 100;
        if(cp == ue){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}