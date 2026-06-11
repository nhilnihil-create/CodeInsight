#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include<bitset>
#include<stdio.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 100000000;

bool isOK(int a[],int index,int key){
    if(a[index] >= key){
        return true;
    }else{
        return false;
    }
}

int binary_search(int a[],int n,int key){
    int left = -1;
    int right = n;

    while(right-left>1){
        int mid = left + (right - left)/2;
        if(isOK(a,mid,key)){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int factrial(int n){
    if(n==0){
        return 1;
    }else{
        return n*factrial(n-1);
    }
}

int main(void){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool flag = true;

    if(abs(b-a)>d){
        flag = false;
    }
    if(abs(b-c)>d){
        flag = false;
    }
    if(abs(c-a)<=d){
        flag = true;
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

