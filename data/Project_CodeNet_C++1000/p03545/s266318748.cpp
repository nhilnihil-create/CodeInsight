#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string num;
    cin >> num;
    int ans=num.at(0)-'0';
    char op1,op2,op3;
    bool b=false;
    
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                ans=num.at(0)-'0';
                if(i){
                    op1='+';
                    ans+=num.at(1)-'0';
                }
                else{
                    op1='-';
                    ans-=num.at(1)-'0';
                }
                if(j){
                    op2='+';
                    ans+=num.at(2)-'0';
                }
                else{
                    op2='-';
                    ans-=num.at(2)-'0';
                }
                if(k){
                    op3='+';
                    ans+=num.at(3)-'0';
                }
                else{
                    op3='-';
                    ans-=num.at(3)-'0';
                }
                if(ans==7){
                    cout << num.at(0)-'0' << op1 << num.at(1)-'0' << op2 << num.at(2)-'0' << op3 << num.at(3)-'0' << '=' << 7 << endl;
                    b=true;
                }
                if(b) break;
            }
            if(b) break;
        }
        if(b) break;
    }
}