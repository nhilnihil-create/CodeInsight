#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 100001
#define ll long long
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    
    int data[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            cin>>data[i][j];
        }
    }
    
    bool point=true;
    while(point){
        point=false;
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                for (int k=0; k<10; k++){
                    if (data[i][j]>data[i][k]+data[k][j]) point=true;
                    data[i][j]=min(data[i][j],data[i][k]+data[k][j]);
                }
            }
        }
    }
    
    ll sum=0;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            int p;
            cin>>p;
            
            if (p==1 || p==-1) continue;
            
            sum+=data[p][1];
        }
    }
    
    cout<<sum<<endl;
}