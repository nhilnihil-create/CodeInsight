#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    long long i = 0;
    long long j = 0;
    long long A = 0; // Aの連続を記憶する変数
    string v;
    int flag = 0;
    long long result = 0;

    for(i = 0; i < s.size(); i++){
        if(s.at(i) == 'C'){
            if(flag == 1){
                v.at(j-1) = 'D';
                flag = 0;
            }else{
                v += s.at(i);
                j++;
            }
        }else if(s.at(i) == 'B'){
            flag = 1;
            v += s.at(i); //代入
            j++;
        }else{
            v += s.at(i); //代入
            j++;
            flag = 0;
        }
    }

    for(i = 0; i < j; i++){
    
        if(v.at(i) == 'A'){
            A++;
        }else  if(v.at(i) == 'B'){
            A = 0;
        }else if(v.at(i) == 'C'){
            A = 0;
        }else if(v.at(i) == 'D'){
            result += A;
        }
    
    }  

    cout << result << endl;
}