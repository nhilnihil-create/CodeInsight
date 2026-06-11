#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &digit, vector<bool> &op_buf, vector<bool> &op, int pos, int sum){

    if((pos == 4) && (sum == 7)){
        op = op_buf;
        return;
    }
    if(pos == 4) return;

    op_buf.at(pos-1) = true;
    dfs(digit, op_buf, op, pos+1, sum+digit.at(pos));
    op_buf.at(pos-1) = false;
    dfs(digit, op_buf, op, pos+1, sum-digit.at(pos));
}

int main(){

    int num;
    cin >> num;

    vector<int> digit(4); 
    vector<bool> op(4); 
    vector<bool> op_buf(4); 
    for(int i=3; i>=0; i--){
        int temp = num%10;
        digit.at(i) = temp;
        num /= 10;
    }

    int sum = digit.at(0), pos = 1;
    dfs(digit, op_buf, op, pos, sum);
    
    for(int i=0; i<3; i++){
        cout << digit.at(i);
        if(op.at(i)==true) cout << '+';
        if(op.at(i)==false) cout << '-';
    }
    cout << digit.at(3) << "=7" << endl;;

    return 0;
}