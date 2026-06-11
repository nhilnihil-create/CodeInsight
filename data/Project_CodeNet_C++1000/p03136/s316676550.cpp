#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){

    int n;

    cin >> n;

    int l[n];

    for(int i=0;i<n; i++){
        cin >> l[i];
    }

    int max = l[0];
    int maxN = 0;
    int r = 0;

    for(int i=0; i<n; i++){
        if(max < l[i]){
            max = l[i];
            maxN = i;
        }
        r += l[i];
    }

    r -= l[maxN];

    if(r <= max){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    


}