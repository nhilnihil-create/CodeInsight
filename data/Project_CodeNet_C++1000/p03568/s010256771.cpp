#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;

    cin >> n;

    int a;

    int sum = 1;

    for(int i = 0; i < n; i++){
        cin >> a;
        if(a % 2 == 0){
            sum *= 2;
        }
        else{
            sum *= 1;
        }
    }

    int total = 1;
    for(int i = 0; i < n; i++){
        total = total*3;
    }

    cout << total - sum << endl;

    return 0;
}