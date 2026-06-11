#include<bits/stdc++.h>
using namespace std;

    int main(){
        string N;
        int x;
        cin>>N;
        for(int i = 0; i<4; i++){
            if(N.at(i) == '2'){
                x += 1;
            }
        }
        cout << x;
    return 0;}
