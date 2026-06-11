#include <iostream>
using namespace std;

int njou(int n){
    int ans = 1;
    for(int i = 0;i<n;i++){
        ans *= 10;
    }
    return ans;
}

int main(){
    int n;
    int x,f = 0;
    cin >> n;
    x = n;
    //cout << n << endl;
    for(int i = 8;i>=0;i--){
        f += x/njou(i);
        x %= njou(i);
        //cout << "f:" << f << endl;
        //cout << "x:" << x << endl;
    }
    //cout << "for" << endl;
    if(n%f == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}