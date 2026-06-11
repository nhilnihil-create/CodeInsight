#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define INF 10**9+7
using namespace std;
using Graph = vector<vector<int> >;//Graph graph(ノードの数)で生成できる

bool check(long long a,long long b,long long c){
    return true;
}

int main(){
    long long A,B,C;
    cin >> A >> B >> C;
    if(A==B && A==C && B==C){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}