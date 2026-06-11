#include<bits/stdc++.h>
#define ll long long
#define P pair<int ,int>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>edge(n ,vector<int> (n,1));
    for(int i=0;i<n;i++) edge[i][i] = 0;
    int sum = (n * (n-1))/ 2;
    if(n % 2 == 1){
        for(int i=0;i< n/2 ;i++){
            edge[i][n-i-2] = 0;
            sum--;
        }
    }
    if(n % 2 == 0){
        for(int i=0;i<n/2;i++){
            edge[i][n-i-1] = 0;
            sum--;
        }
    }

    cout << sum << endl;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(edge[i][j]) cout << i+1 << " " <<  j+1 << endl;
        }
    }
}
