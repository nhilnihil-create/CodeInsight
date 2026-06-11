#include <bits/stdc++.h>
using namespace std;
#define f(x) for(int i=0; i<x; i++)
int main(){
    string s1, s2;
    cin >> s1 >> s2;

    char d[256];
    f(256){
        d[i] = '\0';
    }
    f(s1.size()){

        if(d[s1[i]] == s2[i]) continue;
        else{
            if(d[s1[i]] != '\0'){
                cout << "No";
                return 0;
            }
            d[s1[i]] = s2[i];
        }
    }
    f(256){
        d[i] = '\0';
    }
    f(s1.size()){

        if(d[s2[i]] == s1[i]) continue;
        else{
            if(d[s2[i]] != '\0'){
                cout << "No";
                return 0;
            }
            d[s2[i]] = s1[i];
        }
    }
    cout << "Yes";


}
