#include<iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    int s1 = s / 100;
    int s2 = s % 100; 

    if (0 < s1 && s1 < 13) {
        if(0 < s2 && s2 < 13) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else { 
        if(0 < s2 && s2 < 13) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }

}