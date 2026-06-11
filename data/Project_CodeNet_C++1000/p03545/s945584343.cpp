#include<bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

string s;
int ans = 0;
char op_tmp[3], op_ans[3];

void sum_num(int sum, int l, char op){
    if(l>0) op_tmp[l-1] = op;
    if(l == 3){
        if(op_tmp[2] == '+' && sum == 7){
            for(int i=0; i<3; i++){
               op_ans[i] = op_tmp[i]; 
            } 
            return;
        }
        else if(op_tmp[2] == '-' && sum == 7){
            for(int i=0; i<3; i++) {
                op_ans[i] = op_tmp[i];
            }
            return;
        }
        else{
            return;
        }
    }

    sum_num(sum+(s[l+1]-'0'), l+1, '+');
    sum_num(sum-(s[l+1]-'0'), l+1, '-');

}

int main(){

    cin >> s;

    sum_num(s[0]-'0',0,'0');

    cout << s[0] << op_ans[0] << s[1] << op_ans[1] << s[2] << op_ans[2] << s[3] << "=7" << endl;  
}