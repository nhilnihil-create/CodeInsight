#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;
int GCD(int a,int b){
    if(b == 0)return a;
    return GCD(b,a%b);
}
int main(void){
    string S,T;
    cin >> S >> T;
    unordered_map<char,char> mp;
    unordered_map<char,bool> used;
    for(int i=0;i<S.size();i++){
        if(mp[T[i]]){
            if(mp[T[i]] != S[i]){
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            if(used[S[i]]){
                cout << "No" << endl;
                return 0;
            }
            mp[T[i]] = S[i];
            used[S[i]] = true;
        }
    }
    cout << "Yes" << endl;
}
