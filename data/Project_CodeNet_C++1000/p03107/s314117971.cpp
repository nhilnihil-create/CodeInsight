#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;

    int size = (int)S.size();
    vector<int> flags(size, 0);

    int pre_val = S[0] - '0';
    int pre_index = 0;
    int i=1;
    while(i < size){
        int val = S[i] - '0';
        if(val == pre_val){
            pre_val = val;
            pre_index = i;
            i++;
        }else{
            flags[pre_index] = 1;
            flags[i] = 1;
            pre_val = -1;
            for(int j=0; j<size; j++){
                if(flags[j]==0){
                    pre_val = S[j] - '0'; 
                    pre_index = j;
                    break;
                }
            }
            if(pre_val==-1){break;}
            i++;
        }
    }

    int num=0;
    for(int i=0; i<size; i++){
        num += flags[i];
    }

    cout << num << endl;
    return 0;
}