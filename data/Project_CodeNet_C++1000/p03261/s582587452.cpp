#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> Wi(N,"");
    string w;    
    for(int i=0; i<N; i++){
        cin >> w;
        Wi[i] = w;
    }

    for(int i=1; i<N; i++){
        char ch = Wi[i-1][Wi[i-1].size()-1];
        if(Wi[i][0] != ch){
            cout << "No" << endl;
            return 0;
        }

        for(int j=i-1; j >= 0; j--){
            if(Wi[i]==Wi[j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}