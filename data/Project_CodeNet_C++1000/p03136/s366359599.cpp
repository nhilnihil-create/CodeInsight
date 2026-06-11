#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n;

    cin >> n;

    int a[n];

    int max = 0;
    int _m = 0;

    for(int  i = 0; i < n; i++){
        cin >> a[i];

        if(max < a[i]){
            max = a[i];
            _m = i;
        }
    }

    int all = 0;

    for(int i = 0; i < n; i++){
        if(i != _m){
            all += a[i];
        }
    }

    if(all > max){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
     
}