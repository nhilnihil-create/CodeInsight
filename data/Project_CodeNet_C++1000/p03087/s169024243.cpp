#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    int N,Q;
    string S;
    cin >>N >> Q >> S;
    vector<int> t(N+1,0);
    for(int i = 0;i < N;i++){
        if(i+1 < N && S[i] == 'A' && S[i+1] == 'C'){
            t[i+1] = t[i] + 1;
        }else{
             t[i+1] = t[i];
        }
    }
    for(int i = 0;i < Q;i++){
        int l,r;
        cin >> l >> r;
        --l,--r;
        cout << t[r] - t[l] << endl;

    }



}