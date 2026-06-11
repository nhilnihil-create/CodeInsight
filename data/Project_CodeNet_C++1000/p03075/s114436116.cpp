#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    /*
    int a, b , c, d;
    cin >> a >> b >> c >> d ;
    //*/

    //*
    vector<int> vec(5);
    //cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    for(int i = 0; i < 5; i++){
        cin >> vec.at(i);
    }
    int l;
    cin >> l ;
    
    int cnt = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(abs(vec.at(i) - vec.at(j)) > l){
                cnt++;
            }
        }
    }
    
    //sort(vec.begin(), vec.end());
    //*/
    
    //*
    if( cnt == 0 ){
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
    //*/
    
    //cout << a << endl;

    return 0; 
}
