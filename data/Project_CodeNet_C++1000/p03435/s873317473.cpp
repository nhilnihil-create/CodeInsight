#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<vector<int>> vec(3 ,vector<int>(3));
    for(int i=0;i<3;i++)for(int j=0;j<3;j++) cin >> vec[i][j];

    for(int i=0;i<3;i++){
        for(int j=min(vec[i][0] ,min(vec[i][1] ,vec[i][2])) ;j>0;j--){
            vec[i][0]-- ;vec[i][1]--; vec[i][2]--;
        }
    }

    for(int i=0;i<3;i++){
        if(!(vec[0][i] == vec[1][i] && vec[1][i] == vec[2][i])){
            cout <<"No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
