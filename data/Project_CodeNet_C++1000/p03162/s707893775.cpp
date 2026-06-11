#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int ans =0;
    cin >> N;
    vector<vector<int>>vec(100010,vector<int>(3));
    for(int i=0; i<N;i++){
        for(int j=0; j<3; j++){
            cin >> vec.at(i).at(j);
        }
     }
    

    vector<vector<int>>newvec(100010,vector<int>(3,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            for(int z=0; z<3; z++){
                if(j== z)continue;
                newvec.at(i+1).at(z) = max(newvec.at(i+1).at(z),newvec.at(i).at(j) + vec.at(i).at(z));
            }
        }
    }
    
   
    for(int z=0; z<3;z++){
        ans = max(ans,newvec.at(N).at(z));
    }
    cout << ans << endl;
}   
    