#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cma = 0;
    for(int i = 1;i < n;i++){
        string memo = s.substr(i);
        int cme = 0;
        for(char a = 'a';a <= 'z';a++){
            bool c1 = false, c2 = false;
            for(int j = 0;j < i;j++){
                if(s.at(j) == a)c1 = true;
            }
            for(int j = 0;j < memo.size();j++){
                if(memo.at(j) == a)c2 = true;
            }
            if(c1 && c2)cme++;
        }
        if(cma < cme)cma = cme;
    }
    cout << cma << endl;
}