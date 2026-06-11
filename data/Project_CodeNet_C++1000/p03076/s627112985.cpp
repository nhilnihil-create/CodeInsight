#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    int nnum = 10;
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        sum += a;
        if(a%10 != 0){
            nnum = min(nnum, a%10);
            sum += 10-a%10;
        } 
    }   
    cout << sum - (10-nnum) << endl;
    return 0;
}