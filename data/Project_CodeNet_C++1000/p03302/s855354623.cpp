#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int a,b;
    cin >> a >>b;
    if(a+b==15){
        cout<< '+'<<"\n";
    }else if(a*b==15){
        cout<< '*'<<"\n";
    }else{
        cout<<"x";
    }
}
