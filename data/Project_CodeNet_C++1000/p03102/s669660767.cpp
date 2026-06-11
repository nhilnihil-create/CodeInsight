
//Bismillahir Rahmanir Rahim

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n, m, c;
    cin>>n>>m>>c;
    int arr1[m], arr2[m], p, sum=0, cnt=0;
    for(int i=0; i<m; i++) cin>>arr1[i];
    while(n--){
        for(int i=0; i<m; i++){
            cin>>arr2[i];
            p=arr2[i]*arr1[i];
            sum+=p;

        }
        if(sum+c>0) cnt++;
        sum=0;
    }
    cout<<cnt;



}

