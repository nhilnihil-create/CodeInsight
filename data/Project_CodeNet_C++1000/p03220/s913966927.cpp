#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    double n,t,a;cin >> n >> t >> a;
    double h[1010]={};
    for(int i = 0;i < n;i++)cin >> h[i] ;
    double m = 1000000;
    int id = 0;
    for(int i = 0;i < n;i++){
        double tmp = t-(h[i]*0.006);
        //cout << tmp << endl;
        double d = tmp-a;
        if(d < 0)d = -d;
        if(m >d){
            m = d;
            id = i+1;
        }
    }
    cout << id << endl;
}