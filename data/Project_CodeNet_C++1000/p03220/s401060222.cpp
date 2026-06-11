#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int t,a;
    cin >> t >> a;
    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int dis;
    int minN = 0;
    int min = a*1000 - (t*1000 - h[0]*6);
    if(min < 0){
        min = -min;
    }

    for(int i=0; i<n; i++){
        dis =(t*1000 - h[i]*6) - a*1000;

        if(dis < 0){
            dis = -dis;
        }

        if(min > dis){
            min = dis;
            minN = i;
        }

    }

    
    cout << minN+1 << endl;
}