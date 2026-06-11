#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char S[100000];
    int s_len,i,change=0,max=0;
    cin >> S;
    s_len = strlen(S);
    if(S[0]=='1'){
        change++;
    }
    for(i=1;i<s_len-max;i++){
        if(change==0){
            if(S[i]=='1'){
                max = i;
                change++;
            }
        }else{
            if(S[i]=='0'){
                max = i;
                change--;
            }
        }
    }
    if(max < s_len - max){
        max = s_len - max;
    }
    cout << max << endl;
    return 0;
}