#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    int D;
    cin >> D;
    string s = "Christmas";
    if(D == 24) s += " Eve";
    if(D == 23) s += " Eve Eve";
    if(D == 22) s += " Eve Eve Eve";
   cout << s << endl;
}