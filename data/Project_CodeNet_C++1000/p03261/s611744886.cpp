#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string w[n];

    for(int i=0;i<n;i++){
        cin >> w[i];
    }

    int flag = 0;
    int c;

    for(int i=0;i<n;i++){
        c = 0;
        for(int j=0;j<n;j++){
            if(w[i]==w[j]){
                c++;
            }
        }
        if(c >= 2){
            flag = 1;
        }
    }
    //cout << c << flag << endl;
    char first;
    char last;
    for(int i=1; i<n;i++){
        first = w[i][0];
        last = w[i-1][w[i-1].size()-1];
        if(first != last){
            flag++;
        }
        //cout << last << endl;
    }
    if(flag == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}