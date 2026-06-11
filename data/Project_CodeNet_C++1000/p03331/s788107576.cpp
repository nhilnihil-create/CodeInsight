#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;

int digitsSum(int x){
    int ans=0;
    while(1){
        ans+=x%10;
        x/=10;
        if(x<1){
            break;
        }
    }
    return ans;
}

int main(){

    int N,min=INT32_MAX,temp;
    cin >> N;

    for(int A=1;A<=(N/2);A++){
        int B=N-A;

        temp=digitsSum(A)+digitsSum(B);
        if(temp<min){
            min=temp;
        }
    }

    cout << min<<endl;

    return 0;
}
