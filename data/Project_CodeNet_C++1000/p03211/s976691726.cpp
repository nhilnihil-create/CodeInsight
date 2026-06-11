#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int min = 10000;
    int res=0;
    string dis = "";
    for(int i=0; i<s.length()-2; i++){
        dis = "";
        dis = s.substr(i, 3); // 部分文字列の取得
        res = abs(atoi(dis.c_str())-753);
        if(res < min) 
            min = res;
    }

    cout << min << endl;
    return 0;
}
