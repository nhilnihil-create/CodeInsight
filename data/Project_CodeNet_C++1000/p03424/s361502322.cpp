#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    //string s = "";
    string temp = "";

    // PWGY

    int cnt = 0;
    bool P = false;
    bool W = false;
    bool G = false;
    bool Y = false;

    for (int i = 0; i < N; i++) {
        cin >> temp;

        if (temp == "P" && !P){
            P = true;
            cnt++;
        }

        if (temp == "W" && !W){
            W = true;
            cnt++;
        }
        if (temp == "G" && !G){
            G = true;
            cnt++;
        }
        if (temp == "Y" && !Y){
            Y = true;
            cnt++;
        }
    }
    //cout <<  << endl;
    if (cnt == 3){
        cout << "Three" << endl;
    }
    if (cnt == 4){
        cout << "Four" << endl;
    }

    return 0;

}



