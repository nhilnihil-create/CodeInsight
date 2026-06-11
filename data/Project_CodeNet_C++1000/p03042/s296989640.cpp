#include<bits/stdc++.h>
using namespace std;
bool p(int a){
    if(0 < a && a < 13) return true;
    else return false;
}
int main(){
    int s;
    cin >> s;
    int a = s/100;
    int b = s%100;
    if(!p(a) && p(b)) cout << "YYMM" << endl;
    if(p(a) && !p(b)) cout << "MMYY" << endl;
    if(!p(a) && !p(b)) cout << "NA" << endl;
    if(p(a) && p(b)) cout << "AMBIGUOUS" << endl;
}