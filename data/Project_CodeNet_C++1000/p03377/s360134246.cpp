#include<iostream>
using namespace std;
int main(){
    int a, b, x;
    cin >> a >> b >> x;
    bool judge = false;
    if(x >= a && (x - a) <= b ){
        judge = true;
    }
    if(judge){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}