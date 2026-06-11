#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<char> s1(3),s2(3),rs1(3),rs2(3);

    for(int i = 0;i < 3;i++){
        cin >> s1.at(i);
    }

    for(int i = 0;i < 3;i++){
        cin >> s2.at(i);
    }

    rs1 = s1;
    rs2 = s2;
    
    s1.at(0) = s2.at(2);
    s1.at(1) = s2.at(1);
    s1.at(2) = s2.at(0);

    s2.at(0) = rs1.at(2);
    s2.at(1) = rs1.at(1);
    s2.at(2) = rs1.at(0); 

    if(s1 == rs1 && s2 == rs2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}