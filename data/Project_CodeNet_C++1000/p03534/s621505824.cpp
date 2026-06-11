#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int a, b, c;
    a = b = c = 0;

    for(int i = 0;i < s.size();i++){
        if(s[i] == 'a'){
            a++;
        }else if(s[i] == 'b'){
            b++;
        }else{
            c++;
        }
    }

    if(max(a, max(b, c)) - min(a, min(b, c)) <= 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}

