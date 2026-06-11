#include<iostream>
#include<vector>//可変長配列
#include<algorithm>//sort,二分探索,など
#include<map>//map(辞書)

using namespace std;

int main(void){
    int N, a, b;
    string s;
    cin >> N >> s;
    a = b = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'R'){a+=1;}
        else{b+=1;}     
    }

    if(a > b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}