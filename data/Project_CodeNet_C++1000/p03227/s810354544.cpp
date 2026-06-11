#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//        tmp = stoi(S.substr(i,3));

int main(){

    string S;

    cin >> S;


    char tmp;

    if(S.size() == 3)
    {
        swap(S[0],S[2]);
    }

    cout << S << endl;
    return 0;
}

