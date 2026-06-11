#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;

    string target = "keyence";
    int target_size = (int)target.size();

    for(int k=0; k<(int)S.size(); k++){
        for(int j=k; j<S.size(); j++){
            string s1 = S.substr(0,k);
            string s2 = S.substr(j,S.size()-j);
            if(s1+s2 == target){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
    
}