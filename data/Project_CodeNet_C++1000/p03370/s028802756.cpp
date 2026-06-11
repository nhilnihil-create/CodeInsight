#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,x;
    cin >> n >> x;
    vector<int> vec(n);
    int total = 0;
    int min = 100000;
    for (int i = 0; i < n; i++){
        cin >> vec.at(i);
        total += vec.at(i);
        if(min > vec.at(i)) min = vec.at(i);
    }
    int canmake=0;
    int count = 0;
    canmake = x - total;
    while (1){
        if (canmake >= min){
            canmake -= min;
            count++;
        }else{
            break;
        }
    }
    cout << count + n << endl;
    
}