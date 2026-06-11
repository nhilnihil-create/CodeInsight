#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    string s;
    cin >> s;
    string front = s.substr(0, 2);
    string back = s.substr(2, 2);

    int frontNum = stoi(front);
    int backNum = stoi(back);

    bool frontMM = false;
    bool backMM = false;

    if(1 <= backNum && backNum <= 12){
        backMM = true;
    }

    if(1 <= frontNum && frontNum <= 12){
        frontMM = true;
    }

    if(frontMM && backMM){
        cout << "AMBIGUOUS";
    }else if(frontMM){
        cout << "MMYY";
    }else if(backMM){
        cout << "YYMM";
    }else{
        cout << "NA";
    }

    return 0;
}