#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<vector<int>>vec(2,vector<int>(N));
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin >> vec.at(i).at(j);
        }
    }
    int maxx=0;
    for(int i=0;i<N;i++){
        int sum=0;
        for(int j=0;j<=i;j++){
        sum+=vec.at(0).at(j);
        }
        for(int j=i;j<N;j++){
        sum+=vec.at(1).at(j);
        }
        maxx=max(sum,maxx);
    }
    cout <<maxx<<endl;

}