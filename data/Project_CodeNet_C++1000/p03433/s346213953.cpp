#include<iostream>
using namespace std;
int main(){
    int n,a;
    cin >> n >> a;
    int key = n%500;
    if(key <= a){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}