#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N,X;
    cin >> N >> X;
    vector<int> m(N);
    for(int i=0;i<N;i++){
        cin >> m.at(i) ;
    }
    //まず、それぞれ一個は必ず作るので
    
    int dec=0;
    for(int i=0;i<N;i++){
        dec = dec + m.at(i);
    }
    int x = X - dec;
    int total_number = N;
    int min_m = X;
    for(int i=0;i<N;i++){
        if(min_m > m.at(i)){
            min_m = m.at(i) ;
        }
    }
    cout << N +  x/min_m << endl;
    
    
}