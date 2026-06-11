#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int lE = 0;
    int lW = 0;
    int rE = 0;
    int rW = 0;

    for(int i = 1; i < n; i++){
        if(s[i] == 'E'){rE++;}
        else{rW++;}
    }
    int cnt = lW + rE;
    for(int i = 0; i < n-1; i++){
        int k;
        if(s[i] == 'W'){lW++;}
        else{lE++;}
        if(s[i+1] == 'W'){rW--;}
        else{rE--;}
        k = lW + rE;
        if(cnt > k){cnt = k;}
    }

    cout << cnt << endl;
}