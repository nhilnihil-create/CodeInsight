#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;
    
    vector<int> cnt(S.size());
    int i = 0;
    while(i < S.size()){
        if(S.at(i) == 'A' || S.at(i) == 'T' || S.at(i) == 'C' || S.at(i) == 'G'){
            int j = i;
            while(j < S.size()){
                if(S.at(j) == 'A' || S.at(j) == 'T' || S.at(j) == 'C' || S.at(j) == 'G'){
                    cnt.at(i)++;
                    j++;
                    continue;
                }
                i++;
                break;
            }
        }
        i++;
    }
    
    int max = 0;
    for(int i = 0 ; i < cnt.size() ; i++){
        if(max < cnt.at(i)){
            max = cnt.at(i);
        }
    }
    cout << max << endl;
}