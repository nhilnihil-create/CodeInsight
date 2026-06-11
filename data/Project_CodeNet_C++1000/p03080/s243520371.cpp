#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    int red, blue;
    red = count(S.begin(), S.end(), 'R');
    blue = count(S.begin(), S.end(), 'B');
    if(red > blue){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}