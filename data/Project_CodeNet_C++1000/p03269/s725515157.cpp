#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main(){
    int L;  cin >> L;
    int r = log2(L);
    vector<vector<int>> edge(r+1, vector<int>());
    for(int i=1; i<=r; i++){
        edge[i].push_back(0);
        edge[i].push_back(pow(2, i-1));
    }

    int M = 2*r;
    for(int i=r; i>=1; i--){
        int X = L - pow(2, i-1);
        if(X >= pow(2, r)){
            edge[i].push_back(X);
            L -= (L-X);
            M++;
        }
    }
    int N = r+1;
    cout << N << " " << M << endl;
    for(int i=1; i<=r; i++){
        int n = edge[i].size();
        for(int j=0; j<n; j++){
            cout << i << " " << (j<2 ? i+1:N) << " " << edge[i][j] << endl;
        }
    }
}
