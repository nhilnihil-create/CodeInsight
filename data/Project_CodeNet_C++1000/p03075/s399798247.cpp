#include<vector>
#include <iostream>
#include<string>
#include <complex>

using namespace std;

int main(){
    int k;
    int a[5];
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }
    cin >> k;

    int _a = 0;
    int flag = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i != j){
                _a = abs(a[i]-a[j]);
            }
            if(_a > k){
                flag++;
            }
        }
    }

    if(flag == 0){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }

}