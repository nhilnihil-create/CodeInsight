#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<iosfwd>
#include<sstream>
#include<math.h>
#define N 100
using namespace std;
int main(){
    int a[6];
    int b[4]= {0,0,0,0};
    int cnt=0;
    for(int i=0; i<6; i++){
        int d;
        cin >> d;
        b[d-1]++;
        if(b[d-1]==2) cnt++;
        else if(b[d-1]>2) {cnt=3; break;}
    }
    if(cnt==2) cout << "YES" << endl;
    else cout << "NO" << endl;

}