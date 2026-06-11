#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> a(10);
    for(int i=0; i<a.size(); i++){
        if(i == 4 || i == 7) continue;
        else {
            a.at(i) = int(s.at(i));
        }
    }
    long long  num = 0;
    //2019004030
    long long  b = 1000000000; 
    for(int i=0; i<a.size(); i++){
        num += a.at(i) * b;
        b = b * 0.1;
    }

    if(num <= 55347532558) puts("Heisei");
    else puts("TBD");
}