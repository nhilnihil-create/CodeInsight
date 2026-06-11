#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    char str[64];
    cin >> str;

    if(str[k-1] > 90){
        str[k-1] -= 32;
    }else{
        str[k-1] += 32;
    }

    cout << str << endl;
    return 0;
    

}